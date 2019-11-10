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
        return w<o.w;
    }
};
vector< A> g[2505];
priority_queue< A> heap;
int maxx[2505];
int main(){
    int n,m,st,en,k,u,v,w;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d %d %d",&u,&v,&w);
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    scanf("%d %d %d",&st,&en,&k);
    maxx[st] = 1e9;
    heap.push({st,maxx[st]});
    while(!heap.empty()){
        A now = heap.top();
        heap.pop();
        if(now.v == en){
            printf("%d\n",(int)ceil((double)k/(maxx[en]-1)));
            return 0;
        }
        for(int i=0;i<g[now.v].size();i++){
            if(maxx[g[now.v][i].v]<min(now.w,g[now.v][i].w)){
                maxx[g[now.v][i].v] = min(now.w,g[now.v][i].w);
                heap.push({g[now.v][i].v,maxx[g[now.v][i].v]});
            }
        }
    }
    return 0;
}
