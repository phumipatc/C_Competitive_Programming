/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
vector<int > g[200010];
priority_queue<int > heap;
int child[200010],dis[200010];
void dfs(int u,int p){
	for(auto x:g[u]){
		if(x == p)	continue;
		dis[x] = dis[u]+1;
		child[u]++;
		dfs(x,u);
	}
}
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int n,k,u,v;
	cin >> n >> k;
	for(int i=1;i<n;i++){
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1,0);
	for(int i=1;i<=n;i++)
		heap.push(dis[i]-child[i]);
	int ans = 0;
	while(k--){
		ans+=heap.top();
		heap.pop();
	}
	cout << ans << '\n';
	return 0;
}