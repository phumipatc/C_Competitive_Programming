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
vector< A> g[20005];
priority_queue< A> heap;
int mark[20005],dis[20005],dis2[20005];
int main(){
    int n,m,u,v,w,st,en,k;
    scanf("%d %d %d %d %d",&n,&m,&st,&en,&k);
    for(int i=0;i<m;i++){
        scanf("%d %d %d",&u,&v,&w);
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    for(int i=0;i<n;i++)
        dis[i] = dis2[i] = 1e9;
    heap.push({st,0});
    dis[st] = 0;
    while(!heap.empty()){
        A now = heap.top();
        heap.pop();
        mark[now.v] = 1;
        for(int i=0;i<g[now.v].size();i++){
            if(!mark[g[now.v][i].v] && dis[g[now.v][i].v]>now.w+g[now.v][i].w){
                dis[g[now.v][i].v] = now.w+g[now.v][i].w;
                heap.push({g[now.v][i].v,dis[g[now.v][i].v]});
            }
        }
    }
    memset(mark,0,sizeof mark);
    heap.push({en,0});
    dis2[en] = 0;
    while(!heap.empty()){
        A now = heap.top();
        heap.pop();
        mark[now.v] = 1;
        for(int i=0;i<g[now.v].size();i++){
            if(!mark[g[now.v][i].v] && dis2[g[now.v][i].v]>now.w+g[now.v][i].w){
                dis2[g[now.v][i].v] = now.w+g[now.v][i].w;
                heap.push({g[now.v][i].v,dis2[g[now.v][i].v]});
            }
        }
    }
    for(int i=0;i<n;i++)
        if(i!=st && i!=en)
            if(dis[i]+dis2[i]>k)
                printf("%d ",i);
    return 0;
}
/*
5 6
0 4 17
0 1 6
1 2 5
3 2 8
2 4 8
0 3 5
4 1 9
*/
