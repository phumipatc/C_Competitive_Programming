/*
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Algo	: DP on Tree
	Status	: Finished
*/
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int ,int >;
using PLL = pair<long long ,long long >;
const int dir4[2][4] = {{1,-1,0,0},{0,0,1,-1}};
const int dir8[2][8] = {{-1,-1,-1,0,1,1,1,0},{-1,0,1,1,-1,0,1,-1}};
LL minN(vector<LL > a){
	LL minn = 1e18;
	for(auto x:a)
		minn = min(minn,x);
	return minn;
}
vector<int > g[10010];
int a[10010];
int dp[10010][3];
int dfs(int u,int p,int state){
	if(dp[u][state]!=-1)	return dp[u][state];
	int sum = 0,minn = 1e9;
	sum+=(state == 1)*a[u];
	for(auto x:g[u]){
		if(x == p)	continue;
		if(state == 0)		sum+=min(dfs(x,u,1),dfs(x,u,2));
		else if(state == 1)	sum+=minN({dfs(x,u,0),dfs(x,u,1),dfs(x,u,2)});
		else{
			minn = min(minn,max(dfs(x,u,1)-dfs(x,u,2),0));
			sum+=min(dfs(x,u,1),dfs(x,u,2));
		}
	}
	if(state == 2)	return dp[u][state] = sum+minn;
	else			return dp[u][state] = sum;
}
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int n,u,v;
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	for(int i=1;i<n;i++){
		cin >> u >> v;
		g[u].emplace_back(v);
		g[v].emplace_back(u);
	}
	memset(dp,-1,sizeof dp);
	cout << min(dfs(1,0,1),dfs(1,0,2));
	return 0;
}