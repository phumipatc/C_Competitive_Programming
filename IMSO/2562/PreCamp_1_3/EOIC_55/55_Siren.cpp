/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long v,w,lim;
    bool operator < (const A&o) const{
        return w>o.w;
    }
};
A now;
vector<A > g[50010];
priority_queue<A > heap;
long long dis[50010],dis2[50010];
pair<long long ,long long > p[50010];
long long mark[50010];
int main(){
    long long n,m,k,u,v,w;
    scanf("%lld %lld %lld",&n,&m,&k);
    while(m--){
        scanf("%lld %lld %lld",&u,&v,&w);
        g[u].push_back({v,w,0});
        g[v].push_back({u,w,0});
    }
    for(long long i=1;i<=n;i++)   dis[i] = 1e18;
    dis[n] = 0;
    heap.push({n,0,(long long )1e18});
    while(!heap.empty()){
        now = heap.top();
        heap.pop();
        for(auto x:g[now.v]){
            if(dis[x.v]<=now.w+x.w)    continue;
            dis[x.v] = now.w+x.w;
            heap.push({x.v,dis[x.v],now.lim});
        }
    }
    for(long long i=1;i<=n;i++)   dis2[i] = 1e18;
    for(long long i=1;i<=k;i++){
        scanf("%lld %lld",&p[i].first,&p[i].second);
        mark[p[i].first] = 1;
        dis2[p[i].first] = dis[p[i].first];
        heap.push({p[i].first,dis2[p[i].first],p[i].second});
    }
    while(!heap.empty()){
        now = heap.top();
        heap.pop();
        for(auto x:g[now.v]){
            if((x.w+now.w)-dis[x.v]>now.lim)  continue;
            dis2[x.v] = x.w+now.w;
            mark[x.v] = 1;
            heap.push({x.v,dis2[x.v],now.lim});
        }
    }
    // for(int i=1;i<=n;i++)   printf("%d ",dis[i]);
    // cout << endl;
    // for(int i=1;i<=n;i++)   printf("%d ",dis2[i]);
    // cout << endl;
    for(long long i=1;i<n;i++){
        printf("%lld\n",mark[i]);
    }
	return 0;
}
/*
4 5 1
1 2 20
2 3 5
2 4 3
1 4 10
3 4 2
2 7
*/