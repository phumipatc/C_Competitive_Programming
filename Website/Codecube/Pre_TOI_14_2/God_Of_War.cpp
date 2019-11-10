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
    bool operator < (const A&o) const{
        return w>o.w;
    }
};
A now;
vector< A> g[100001];
priority_queue< A> heap;
int dis[100001],dis2[100001];
int main(){
    int n,m,st,en,u,v,w;
    scanf("%d %d %d %d",&n,&m,&st,&en);
    for(int i=1;i<=m;i++){
        scanf("%d %d %d",&u,&v,&w);
        dis[n]+=w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    for(int i=0;i<n;i++)    dis[i] = dis2[i] = 1e9;
    dis[st] = dis2[en] = 0;
    heap.push({st,0});
    while(!heap.empty()){
        now = heap.top();
        heap.pop();
        for(int i=0;i<g[now.v].size();i++){
            if(dis[g[now.v][i].v]>now.w+g[now.v][i].w){
                dis[g[now.v][i].v] = now.w+g[now.v][i].w;
                heap.push({g[now.v][i].v,dis[g[now.v][i].v]});
            }
        }
    }
    heap.push({en,0});
    while(!heap.empty()){
        now = heap.top();
        heap.pop();
        for(int i=0;i<g[now.v].size();i++){
            if(dis2[g[now.v][i].v]>now.w+g[now.v][i].w){
                dis2[g[now.v][i].v] = now.w+g[now.v][i].w;
                heap.push({g[now.v][i].v,dis2[g[now.v][i].v]});
            }
        }
    }
    int ans = -1;
    for(int i=0;i<n;i++)
        for(int j=0;j<g[i].size();j++)
            ans = max(ans,dis[n]-dis[i]-dis2[g[i][j].v]);
    printf("%d\n",ans);
    return 0;
}
