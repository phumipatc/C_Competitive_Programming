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
vector< A> g[2600];
priority_queue< A> heap;
int maxx[2600];
int main(){
    int n,m,u,v,w,st,en,tourist;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d %d %d",&u,&v,&w);
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    scanf("%d %d %d",&st,&en,&tourist);
    maxx[st]=1e9;
    heap.push({st,maxx[st]});
    while(!heap.empty()){
        A now=heap.top();
        heap.pop();
        if(now.v==en){
            printf("%d\n",(int)ceil((double)tourist/(maxx[en]-1)));
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
/*
7 10
1 2 30
1 3 15
1 4 10
2 4 25
2 5 60
3 4 40
4 7 35
3 6 20
5 7 20
7 6 30
1 7 99
*/
