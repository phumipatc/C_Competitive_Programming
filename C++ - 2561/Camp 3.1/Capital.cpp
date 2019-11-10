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
vector<A > g[100010];
priority_queue<A > heap;
int dis[100010];
int main(){
    int n,u,v,w;
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        scanf("%d %d %d",&u,&v,&w);
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    for(int i=1;i<=n;i++)
        dis[i] = 1e9;
    dis[1] = 0;
    heap.push({1,0});
    while(!heap.empty()){
        now = heap.top();
        heap.pop();
        for(auto x:g[now.v]){
            if(dis[x.v]<=now.w+x.w) continue;
            dis[x.v] = now.w+x.w;
            heap.push({x.v,dis[x.v]});
        }
    }
    int maxx = 0;
    for(int i=1;i<=n;i++)
        maxx = max(maxx,dis[i]);
    printf("%d\n",maxx);
	return 0;
}