/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
struct A{
	int v,w,id;
	bool operator < (const A&o) const{
		return w>o.w;
	}
};
A now;
vector<A > g[1010];
priority_queue<A > heap;
int dis[1010][2];
int n;
int solve(int lim){
	for(int i=1;i<=n;i++)
		dis[i][0] = dis[i][1] = 1e9;
	dis[1][1] = 0;
	heap.push({1,0,1});
	while(!heap.empty()){
		now = heap.top();
		heap.pop();
		for(auto x:g[now.v]){
			if(x.id>lim)						continue;
			if(now.w+x.w>=dis[x.v][!now.id])	continue;
			dis[x.v][!now.id] = now.w+x.w;
			heap.push({x.v,now.w+x.w,!now.id});
		}
	}
	return dis[n][0];
}
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int m,u,v,w,diss;
	cin >> n >> m;
	for(int i=1;i<=m;i++){
		cin >> u >> v >> w;
		g[u].push_back({v,w,i});
		g[v].push_back({u,w,i});
	}
	diss = solve(m);
	int l = 1,r = m;
	while(l<r){
		int mid = (l+r)/2;
		int now = solve(mid);
		if(now>diss)	l = mid+1;
		else			r = mid;
	}
	cout << l << ' ' << diss << '\n';
	return 0;
}