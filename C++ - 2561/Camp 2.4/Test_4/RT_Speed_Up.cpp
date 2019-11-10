/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int v,w,sp,last;
    bool operator < (const A&o) const{
        return w>o.w;
    }
};
A now;
vector< A> g[80010];
priority_queue< A> heap;
int speed[10],potion[80010],dis[80010][10];
int main(){
    int n,m,l,q,u,v,w;
    speed[0] = 1;
    for(int i=1;i<=8;i++)
        speed[i] = speed[i-1]*2;
    scanf("%d %d %d %d",&n,&m,&l,&q);
    for(int i=1;i<=m;i++){
        scanf("%d %d %d",&u,&v,&w);
        g[u].push_back({v,w,0,0});
    }
    for(int i=1;i<=l;i++){
        scanf("%d",&v);
        potion[v] = 1;
    }
    for(int i=1;i<=n;i++)
        for(int j=0;j<=q;j++)
            dis[i][j] = 1e9;
    dis[1][0] = 0;
    heap.push({1,0,0,0});
    while(!heap.empty()){
        now = heap.top();
        heap.pop();
        if(now.v == n){
            printf("%d\n",now.w);
            return 0;
        }
        for(auto x:g[now.v]){
            if(potion[now.v] && now.v!=now.last && now.sp<q && dis[x.v][now.sp+1]>now.w+(x.w/speed[now.sp+1])){
                dis[x.v][now.sp+1] = now.w+(x.w/speed[now.sp+1]);
                heap.push({x.v,dis[x.v][now.sp+1],now.sp+1,now.v});
            }
            if(dis[x.v][now.sp]>now.w+(x.w/speed[now.sp])){
                dis[x.v][now.sp] = now.w+(x.w/speed[now.sp]);
                heap.push({x.v,dis[x.v][now.sp],now.sp,now.last});
            }
        }
    }
    return 0;
}
