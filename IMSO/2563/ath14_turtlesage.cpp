/*
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Algo	: DP on Tree
	Status	: Finished
*/
#include<bits/stdc++.h>
#define all(x) begin(x),end(x)
#define allst(x,y) (x).begin()+y,(x).end()
#define sz(x) (int)(x).size()
#define decp(x) fixed << setprecision(x)
#define MOD (LL )(1e9+7)
using namespace std;
using LL = long long;
using PII = pair<int ,int >;
using PLL = pair<long long ,long long >;
const int dir4[2][4] = {{1,-1,0,0},{0,0,1,-1}};
const int dir8[2][8] = {{-1,-1,-1,0,1,1,1,0},{-1,0,1,1,-1,0,1,-1}};
const int MAX_INT = 1e9;
const LL MAX_LL = 1e18;
LL modN(LL a,LL b,LL c = MOD){
	if(b == 0)	return 0;
	if(b == 1)	return a%c;
	LL now = modN(a,b/2);
	if(b&1)	return (((now*now)%c)*(a%c))%c;
	else	return (now*now)%c;
}
vector<int > g[100010],dp[100010];
int a[100010],val[100010];
void dfs(int u,int p){
	if(a[u])	dp[u].push_back(val[u]);
	for(auto x:g[u]){
		if(x == p)	continue;
		dfs(x,u);
		if(dp[x].empty())	continue;
		dp[u].push_back(dp[x][0]+val[u]);
	}
	sort(all(dp[u]),greater<int >());
}
void solve(){
	int n,u,v;
	cin >> n;
	for(int i=1;i<n;i++){
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int i=1;i<=n;i++)
		cin >> val[i];
	for(int i=1;i<=n;i++)
		cin >> a[i];
	dfs(1,0);
	int maxx = -2e9;
	for(int i=1;i<=n;i++){
		if(a[i])				maxx = max(maxx,dp[i][0]);
		if(dp[i].size()>1)		maxx = max(maxx,dp[i][0]+dp[i][1]-val[i]);
	}
	if(maxx>0)	cout << maxx << '\n';
	else		cout << "Stay Home\n";
	for(int i=1;i<=n;i++)
		g[i].clear(),dp[i].clear();
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int q = 1;
	cin >> q;
	for(int Q=1;Q<=q;Q++){
		// cout << "Case #" << Q << ": ";
		solve();
	}
	return 0;
}
/*
2
3
1 2
2 3
5 20 -10
1 0 1
4
1 2
2 3
3 4
-1 5 -20 -1
1 0 0 1
*/