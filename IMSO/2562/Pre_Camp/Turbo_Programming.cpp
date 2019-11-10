/*
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
vector<A > g[1010];
priority_queue<A > heap;
int dis[1010];
int main(){
    int n,m,q,u,v,w;
    scanf("%d %d %d",&n,&m,&q);
    while(m--){
        scanf("%d %d %d",&u,&v,&w);
        g[u].push_back({v,w});
    }
    for(int i=1;i<=n;i++){
        dis[i] = 1e9;
    }
    u = 1;
    dis[u] = 0;
    heap.push({u,0});
    while(!heap.empty()){
        now = heap.top();
        heap.pop();
        for(auto x:g[now.v]){
            if(dis[x.v]<=now.w+x.w) continue;
            dis[x.v] = now.w+x.w;
            heap.push({x.v,dis[x.v]});
        }
    }
    while(q--){
        scanf("%d",&v);
        if(dis[v] == 1e9)   printf("-1\n");
        else                printf("%d\n",dis[v]);
    }
	return 0;
}