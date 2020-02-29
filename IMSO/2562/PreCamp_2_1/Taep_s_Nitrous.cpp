/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
struct A{
	int v,w,k;
	bool operator < (const A&o) const{
		if(w!=o.w)	return w>o.w;
		else		return k>o.k;
	} 
};
A now;
vector<A > g[5010];
priority_queue<A > heap;
int dis[5010][110];
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int n,m,k,u,v,w;
	cin >> n >> m >> k;
	while(m--){
		cin >> u >> v >> w;
		g[u].push_back({v,w,0});
		g[u].push_back({v,w/2,1});
		g[v].push_back({u,w,0});
		g[v].push_back({u,w/2,1});
	}
	for(int i=1;i<=n;i++)
		for(int j=0;j<=k;j++)
			dis[i][j] = 1e9;
	dis[1][0] = 0;
	heap.push({1,0,0});
	int minn = 1e9;
	while(!heap.empty()){
		now = heap.top();
		heap.pop();
		// printf("%d %d %d\n",now.v,now.w,now.k);
		if(now.v == n){
			minn = min(minn,now.w);
			if(now.k == 0)	break;
		}
		for(auto x:g[now.v]){
			if(now.k+x.k>k)									continue;
			if(dis[x.v][now.k+x.k]<=dis[now.v][now.k]+x.w)	continue;
			dis[x.v][now.k+x.k] = dis[now.v][now.k]+x.w;
			heap.push({x.v,dis[x.v][now.k+x.k],now.k+x.k});
		}
	}
	printf("%d\n%d\n%d\n",dis[n][0],minn,dis[n][0]-minn);
	return 0;
}