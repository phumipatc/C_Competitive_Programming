/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long v,w;
    bool operator < (const A&o) const{
        return w>o.w;
    }
};
A now;
priority_queue<A > heap;
vector<A > g[100010];
long long dis[100010],mark[100010];
void dfs(long long now){
    mark[now] = 1;
    for(auto x:g[now]){
        if(mark[x.v])   continue;
        if(dis[x.v]+x.w == dis[now]){
            dfs(x.v);
        }
    }
}
int main(){
    long long n,m,u,v,w,a,b,c,d;
    scanf("%lld %lld",&n,&m);
    while(m--){
        scanf("%lld %lld %lld",&u,&v,&w);
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    scanf("%lld %lld %lld %lld",&a,&b,&c,&d);
    for(long long i=1;i<=n;i++)
        dis[i] = 1e18;
    dis[a] = 0;
    heap.push({a,0});
    while(!heap.empty()){
        now = heap.top();
        heap.pop();
        for(auto x:g[now.v]){
            if(dis[x.v]<=now.w+x.w) continue;
            dis[x.v] = now.w+x.w;
            heap.push({x.v,dis[x.v]});
        }
    }
    dfs(b);
    for(long long i=1;i<=n;i++)
        dis[i] = 1e18;
    dis[c] = 0;
    heap.push({c,0});
    while(!heap.empty()){
        now = heap.top();
        heap.pop();
        for(auto x:g[now.v]){
            if(mark[x.v])           continue;
            if(dis[x.v]<=now.w+x.w) continue;
            dis[x.v] = now.w+x.w;
            heap.push({x.v,dis[x.v]});
        }
    }
    if(dis[d] == 1e18 || mark[c])   printf("-1\n");
    else                            printf("%lld\n",dis[d]);
	return 0;
}
