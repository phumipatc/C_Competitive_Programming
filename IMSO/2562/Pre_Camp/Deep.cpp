/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int l,r;
};
A a[200010],b[200010];
int pre[200010],point[200010],dis[200010],child[200010][20];
int idx = 1,S,A,B;
int dir(){
    int res = ((S&8)>>3);
    S = (S*A+B)%40507;
    return res;
}
void pre_order(int now){
    int st = idx;
    pre[idx++] = now;
    if(a[now].l == -1 && a[now].r == -1){
        point[st] = st;
        dis[st] = 0;
        return ;
    }
    if(a[now].l!=-1 && a[now].r!=-1){
        b[st].l = idx;
        pre_order(a[now].l);
        b[st].r = idx;
        pre_order(a[now].r);
        dis[st] = 0;
        point[st] = st;
    }else{
        b[st].l = idx;
        if(a[now].l!=-1)    pre_order(a[now].l);
        else                pre_order(a[now].r);
        dis[st] = dis[b[st].l]+1;
        point[st] = point[b[st].l];
        child[st][0] = b[st].l;
        for(int i=1;i<=18;i++)
            child[st][i] = child[child[st][i-1]][i-1];
    }
}
void query(int lv){
    int now = 1;
    while(lv>0 && (b[now].l || b[now].r)){
        if(dis[now] == 0){
            if(dir() == 0){
                lv--;
                now = b[now].l;
            }else{
                lv--;
                now = b[now].r;
            }
        }else{
            if(lv>=dis[now]){
                lv-=dis[now];
                now = point[now];
            }else{
                for(int i=18;i>=0;i--){
                    if((1<<i)>lv)           continue;
                    if(child[now][i] == 0)  continue;
                    lv-=(1<<i);
                    now = child[now][i];
                }
            }
        }
    }
    printf("%d\n",pre[now]);
}
int main(){
    int n,q,lv;
    scanf("%d %d",&n,&q);
    for(int i=0;i<n;i++)
        scanf("%d %d",&a[i].l,&a[i].r);
    pre_order(0);
    while(q--){
        scanf("%d %d %d %d",&lv,&S,&A,&B);
        query(lv);
    }
	return 0;
}
/*
9 5
3 -1
-1 -1
1 8
6 7
-1 -1
-1 -1
5 4
-1 2
-1 -1
*/