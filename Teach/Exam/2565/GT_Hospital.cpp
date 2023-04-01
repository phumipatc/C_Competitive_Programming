/*
	Task	: GT_Hospital
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 01 April 2023 [12:11]
	Algo	: 
	Status	: 
*/
#include<bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i <= (b); ++i)
#define repr(i, a, b) for(int i = a; i >= (b); --i)
#define repl(i, a, b) for(LL i = a; i <= (b); ++i)
#define reprl(i, a, b) for(LL i = a; i >= (b); --i)
#define all(x) begin(x),end(x)
#define allst(x,y) (x).begin()+y,(x).end()
#define rmdup(x) sort(all(x)),(x).resize(unique((x).begin(),(x).end())-(x).begin())
#define sz(x) (int)(x).size()
#define decp(x) fixed << setprecision(x)
#define MOD (LL )(1e9+7)
using namespace std;
using LL = long long;
using PII = pair<int ,int >;
using PLL = pair<long long ,long long >;
const int dir4[2][4] = {{1,-1,0,0},{0,0,1,-1}};
const int dir8[2][8] = {{-1,-1,-1,0,1,1,1,0},{-1,0,1,1,-1,0,1,-1}};
LL modN(LL a,LL b,LL c = MOD){
	if(b == 0)	return 1;
	if(b == 1)	return a%c;
	LL now = modN(a,b/2,c);
	if(b&1)	return (((now*now)%c)*(a%c))%c;
	else	return (now*now)%c;
}
const int N = 100010;
vector<PII > g[N];
PII p[N];
int dp[N];
void dfs(int u,int par){
	for(auto x:g[u]){
		if(x.first == par)	continue;
		p[x.first] = {u,x.second};
		dfs(x.first,u);
	}
}
void init(){
	
}
void solve(){
	int n,m,s,q;
	cin >> n >> m >> s >> q;
	rep(i,1,n-1){
		int u,v,w;
		cin >> u >> v >> w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	rep(i,1,n)
		dp[i] = 1e9;
	dp[s] = 0;
	dfs(s,0);
	while(q--){
		int opr,u;
		cin >> opr >> u;
		if(opr == 0){
			dp[u] = 0;
			int sum = 0;
			while(u != 0){
				dp[u] = min(dp[u],sum);
				sum+=p[u].second;
				u = p[u].first;
			}
		}else if(opr == 1){
			int ans = dp[u],sum = 0;
			while(u != 0){
				ans = min(ans,sum + dp[u]);
				sum+=p[u].second;
				u = p[u].first;
			}
			cout << ans << '\n';
		}
	}
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	// freopen("d:/Code/C_Programming/input.in","r",stdin);
	init();
	int q = 1;
	// cin >> q;
	for(int Q=1;Q<=q;Q++){
		// cout << "Case #" << Q << ": ";
		solve();
	}
	return 0;
}
/*
8 2 1 5
1 2 9
1 8 11
6 7 5
6 1 5
3 4 4
4 5 2
4 1 3
0 5
1 3
0 6
1 7
1 5
*/