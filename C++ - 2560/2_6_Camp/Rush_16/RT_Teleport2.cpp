/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int v,w;
};
struct B{
    int v,w,a;
    bool operator < (const B&o) const{
        return w>o.w;
    }
};
B now;
vector< A> g[20005];
priority_queue< B> heap;
int dis[20005];
int main(){
    int n,m,k,a,u,v,w;
    scanf("%d %d %d %d",&n,&m,&k,&a);
    for(int i=1;i<=m;i++){
        scanf("%d %d %d",&u,&v,&w);
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    for(int i=1;i<=k;i++){
        scanf("%d",&w);
        while(w--){
            scanf("%d",&v);
            g[i+n].push_back({v,0});
            g[v].push_back({i+n,0});
        }
    }
    for(int i=2;i<=n+k;i++)
        dis[i] = 1e9;
    heap.push({1,0,a});
    while(!heap.empty()){
        now = heap.top();
        heap.pop();
        if(now.v == n){
            printf("%d\n",dis[n]);
            return 0;
        }
        for(int i=0;i<g[now.v].size();i++){
            if(g[now.v][i].v>n && now.a && dis[g[now.v][i].v]>now.w){
                dis[g[now.v][i].v] = now.w;
                heap.push({g[now.v][i].v,dis[g[now.v][i].v],now.a-1});
            }
            if(g[now.v][i].v<=n && dis[g[now.v][i].v]>now.w+g[now.v][i].w){
                dis[g[now.v][i].v] = now.w+g[now.v][i].w;
                heap.push({g[now.v][i].v,dis[g[now.v][i].v],now.a});
            }
        }
    }
    printf("-1\n");
    return 0;
}
