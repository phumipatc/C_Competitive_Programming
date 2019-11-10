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
A now;
vector< A> g[10100];
priority_queue< A> heap;
int dis[10100],dis2[10100];
int main(){
    int n,m,st,en,k,u,v,w;
    scanf("%d %d %d %d %d",&n,&m,&st,&en,&k);
    for(int i=1;i<=m;i++){
        scanf("%d %d %d",&u,&v,&w);
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    for(int i=0;i<n;i++)   dis[i] = dis2[i] = 1e9;
    heap.push({st,0});
    dis[st] = 0;
    while(!heap.empty()){
        now = heap.top();
        heap.pop();
        if(now.v == en){
            printf("%d %d 0\n",en,dis[en]);
            return 0;
        }
        for(auto x:g[now.v]){
            if(dis[x.v]>x.w+now.w && x.w+now.w<=k){
                dis[x.v] = x.w+now.w;
                heap.push({x.v,dis[x.v]});
            }
        }
    }
    heap.push({en,0});
    dis2[en] = 0;
    while(!heap.empty()){
        now = heap.top();
        heap.pop();
        if(dis[now.v]!=1e9){
            printf("%d %d %d",now.v,dis[now.v],dis2[now.v]);
            return 0;
        }
        for(auto x:g[now.v]){
            if(dis2[x.v]>x.w+now.w){
                dis2[x.v] = x.w+now.w;
                heap.push({x.v,dis2[x.v]});
            }
        }
    }
    return 0;
}
