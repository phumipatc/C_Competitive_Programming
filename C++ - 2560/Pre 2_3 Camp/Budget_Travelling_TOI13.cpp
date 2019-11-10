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
        if(w!=o.w)  return w>o.w;
        else        return v>o.v;
    }
};
vector< A> g[10100];
priority_queue< A> heap;
int dis[10100],mark[10100],dis2[10100];
int main(){
    int n,m,st,en,k,a,b,w;
    scanf("%d %d %d %d %d",&n,&m,&st,&en,&k);
    for(int i=1;i<=m;i++){
        scanf("%d %d %d",&a,&b,&w);
        g[a].push_back({b,w});
        g[b].push_back({a,w});
    }
    for(int i=0;i<n;i++)   dis[i]=dis2[i]=1e9;
    dis[st]=0;
    heap.push({st,0});
    while(!heap.empty()){
        A now=heap.top();
        heap.pop();
        mark[now.v]=1;
        if(now.v==en){
            printf("%d %d 0\n",en,dis[en]);
            return 0;
        }
        for(int i=0;i<g[now.v].size();i++){
            if(dis[g[now.v][i].v]>now.w+g[now.v][i].w && now.w+g[now.v][i].w<=k){
                dis[g[now.v][i].v]=now.w+g[now.v][i].w;
                heap.push({g[now.v][i].v,dis[g[now.v][i].v]});
            }
        }
    }
    dis2[en]=0;
    heap.push({en,0});
    while(!heap.empty()){
        A now=heap.top();
        heap.pop();
        if(mark[now.v]){
            printf("%d %d %d\n",now.v,dis[now.v],dis2[now.v]);
            return 0;
        }
        for(int i=0;i<g[now.v].size();i++){
            if(dis2[g[now.v][i].v]>now.w+g[now.v][i].w){
                dis2[g[now.v][i].v]=now.w+g[now.v][i].w;
                heap.push({g[now.v][i].v,dis2[g[now.v][i].v]});
            }
        }
    }
    return 0;
}
