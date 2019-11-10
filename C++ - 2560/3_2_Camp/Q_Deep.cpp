/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int u,t,jump,child,r;
};
A pre[200010];
vector<int> g[200010];
int s,a,b;
int dir(){
    int res = ((s & 8) >> 3);
    s = (s * a + b) % 40507;
    return res;
}
void dfs(int now,int state){
    if(g[now].size() == 0){
        pre[state].u = now;
        pre[state].t = state;
        pre[state].jump = -1;
        pre[state].child = 0;
        pre[state].r = 0;
    }else if(g[now].size() == 1){
        dfs(g[now][0],state+1);
        pre[state].u = now;
        pre[state].t = state;
        pre[state].jump = max(0,pre[state+1].jump)+1;
        pre[state].child = pre[state+1].child+1;
        pre[state].r = 0;
    }else if(g[now].size() == 2){
        pre[state].u = now;
        pre[state].t = state;
        pre[state].jump = 0;
        dfs(g[now][0],state+1);
        pre[state].child = pre[state+1].child+1;
        pre[state].r = state+pre[state].child+1;
        dfs(g[now][1],state+pre[state].child+1);
        pre[state].child += pre[state+pre[state].child+1].child+1;
    }
}
int main(){
    int n,q,l,r,now,d;
    scanf("%d %d",&n,&q);
    for(int i=0; i<n; i++){
        scanf("%d %d",&l,&r);
        if(l!=-1)
            g[i].push_back(l);
        if(r!=-1)
            g[i].push_back(r);
    }
    dfs(0,0);
//    for(int i=0;i<n;i++)
//        printf("%d %d %d\n",pre[i].u,pre[i].jump,pre[i].child);
    while(q--){
        scanf("%d %d %d %d",&l,&s,&a,&b);
        now = 0;
        while(l>0){
//            printf("now : %d\n",pre[now].u);
            if(pre[now].jump == -1){
                l = 0;
            }else if(pre[now].jump == 0){
                d = dir();
                if(!d)
                    now++;
                else
                    now = pre[now].r;
                l--;
            }else if(pre[now].jump >= l){
                now+=l;
                l = 0;
            }else{
                l-=pre[now].jump;
                now+=pre[now].jump;
            }
        }
        printf("%d\n",pre[now].u);
    }
    return 0;
}
