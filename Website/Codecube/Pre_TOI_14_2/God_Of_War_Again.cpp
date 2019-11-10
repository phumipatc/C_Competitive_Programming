/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int v,w,maxx;
    bool operator < (const A&o) const{
        if(w!=o.w)  return w>o.w;
        else        return maxx<o.maxx;
    }
};
A now;
vector< A> g[100005];
priority_queue< A> heap;
int dis[100005];
int main(){
    int n,m,st,en,u,v,w,sum = 0,maxx = -1;
    scanf("%d %d %d %d",&n,&m,&st,&en);
    for(int i=1;i<=m;i++){
        scanf("%d %d %d",&u,&v,&w);
        sum+=w;
        g[u].push_back({v,w,0});
        g[v].push_back({u,w,0});
    }
    for(int i=0;i<n;i++)
        dis[i] = 1e9;
    heap.push({st,0,0});
    dis[st] = 0;
    while(!heap.empty()){
        now = heap.top();
        heap.pop();
        if(now.v == en){
            maxx = max(maxx,now.maxx);
        }
        for(int i=0;i<g[now.v].size();i++){
            if(dis[g[now.v][i].v]>=now.w+g[now.v][i].w){
                dis[g[now.v][i].v] = now.w+g[now.v][i].w;
                heap.push({g[now.v][i].v,dis[g[now.v][i].v],max(now.maxx,g[now.v][i].w)});
            }
        }
    }
    printf("%d\n",sum-dis[en]+maxx);
    return 0;
}
