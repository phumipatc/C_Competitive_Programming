/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int u,w;
    bool operator < (const A&o) const{
        return w>o.w;
    }
};
A now;
struct B{
    int u,v,w;
};
B a[100100];
vector< A> g[10100],inv[10100];
priority_queue< A> heap;
int dis[10100],dis2[10100];
int main(){
    int n,m,st,en;
    scanf("%d %d %d %d",&n,&m,&st,&en);
    for(int i=1;i<=m;i++){
        scanf("%d %d %d",&a[i].u,&a[i].v,&a[i].w);
        g[a[i].u].push_back({a[i].v,a[i].w});
        inv[a[i].v].push_back({a[i].u,a[i].w});
    }
    for(int i=1;i<=n;i++)
        dis[i] = dis2[i] = 1e9;
    heap.push({st,0});
    dis[st] = 0;
    while(!heap.empty()){
        now = heap.top();
        heap.pop();
        for(auto &x:g[now.u]){
            if(dis[x.u]>now.w+x.w){
                dis[x.u] = now.w+x.w;
                heap.push({x.u,dis[x.u]});
            }
        }
    }
    dis2[en] = 0;
    heap.push({en,0});
    while(!heap.empty()){
        now = heap.top();
        heap.pop();
        for(auto &x:inv[now.u]){
            if(dis2[x.u]>now.w+x.w){
                dis2[x.u] = now.w+x.w;
                heap.push({x.u,dis2[x.u]});
            }
        }
    }
    int ans = 1e9;
    for(int i=1;i<=m;i++){
        if(dis[a[i].u]+dis2[a[i].v]+a[i].w == dis[en])  continue;
        ans = min(ans,dis[a[i].u]+dis2[a[i].v]+a[i].w);
    }
    printf("%d\n",ans);
    return 0;
}
