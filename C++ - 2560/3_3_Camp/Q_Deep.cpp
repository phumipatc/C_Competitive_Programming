/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int u,cross,skip,child;
};
A pre[200100];
vector< int> g[200100];
int s,a,b;
int dir(){
    int res = ((s & 8) >> 3);
    s = (s * a + b) % 40507;
    return res;
}
void dfs(int now,int state){
    pre[state].u = now;
    if(g[now].size() == 0){
        pre[state].skip = -1;
        pre[state].child = pre[state].cross = 0;
    }else if(g[now].size() == 1){
        dfs(g[now][0],state+1);
        pre[state].cross = 0;
        pre[state].child = pre[state+1].child+1;
        pre[state].skip = max(0,pre[state].skip+1);
    }else{
        pre[state].skip = 0;
        dfs(g[now][0],state+1);
        pre[state].child = pre[state+1].child+1;
        pre[state].cross = state+pre[state].child+1;
        dfs(g[now][1],pre[state].cross);
        pre[state].child+=pre[pre[state].cross].child+1;
    }
}
int main(){
    int n,q,l,r;
    scanf("%d %d",&n,&q);
    for(int i=0;i<n;i++){
        scanf("%d %d",&l,&r);
        if(l != -1) g[i].push_back(l);
        if(r != -1) g[i].push_back(r);
    }
    dfs(0,0);
    while(q--){
        scanf("%d %d %d %d",&l,&s,&a,&b);
        int now = 0;
        while(l>0){
            if(pre[now].skip == -1){
                l = 0;
            }else if(pre[now].skip == 0){
                int d = dir();
                if(!d)  now++;
                else    now = pre[now].cross;
                l--;
            }else if(pre[now].skip >= l){
                now+=l;
                l = 0;
            }else{
                l-=pre[now].skip;
                now+=pre[now].skip;
            }
        }
        printf("%d\n",pre[now].u);
    }
    return 0;
}
