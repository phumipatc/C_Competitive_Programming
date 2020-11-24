/*
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Algo	: DP
	Status	: Finished
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int ,int > PII;
typedef pair<long long ,long long > PLL;
vector<int > g[100010];
vector<int > ans;
int dp[100010];
void dfs(int u,int p){
	dp[u] = 1;
	if(g[u].size() == 1)	return ;
	int idx,maxx = -1e9;
	for(auto x:g[u]){
		if(x == p)	continue;
		dfs(x,u);
		if(maxx<dp[x]){
			maxx = dp[x];
			idx = x;
		}
	}
	dp[u]+=dp[idx];
	for(auto x:g[u]){
		if(x == p || x == idx)		continue;
		// printf("from %d: %d\n",u,dp[x]);
		ans.push_back(dp[x]);
	}
}
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int n,u,v;
	cin >> n;
	for(int i=1;i<n;i++){
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1,1);
	ans.push_back(dp[1]);
	sort(ans.begin(),ans.end());
	reverse(ans.begin(),ans.end());
	cout << ans.size() << '\n';
	for(auto x:ans)
		cout << x << '\n';
	return 0;
}