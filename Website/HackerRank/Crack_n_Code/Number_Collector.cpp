/*
	Task	: Number_Collector
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 05 December 2021 [10:45]
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
const int N = 1e5+5;
const int A = 105;
vector<int > g[N];
int in[N],a[N];
LL dp[N][A];
void init(){
	
}
void solve(){
	int n,m,k;
	cin >> n >> m >> k;
	while(m--){
		int u,v;
		cin >> u >> v;
		g[u].emplace_back(v);
		in[v]++;
	}
	rep(i,1,n)
		cin >> a[i];
	queue<int > que;
	vector<int > order;
	que.push(1);
	dp[1][a[1]] = 1;
	while(!que.empty()){
		int now = que.front();
		que.pop();
		order.emplace_back(now);
		for(auto x:g[now]){
			in[x]--;
			dp[x][a[x]]+=dp[now][a[now]],dp[x][a[x]]%=MOD;
			if(!in[x])	que.push(x);
		}
	}
	LL ans = 0;
	for(auto now:order){
		rep(i,1,100){
			ans+=dp[now][i],ans%=MOD;
			dp[now][i]+=dp[now][i-1],dp[now][i]%=MOD;
		}
		for(auto x:g[now]){
			in[x]--;
			dp[x][a[x]]+=(dp[now][min(100,a[x]+k)]-dp[now][max(0,a[x]-k-1)])%MOD,dp[x][a[x]]+=MOD,dp[x][a[x]]%=MOD;
			rep(i,1,100)
				dp[x][i]+=(dp[now][i]-dp[now][i-1])%MOD,dp[x][i]+=MOD,dp[x][i]%=MOD;
			if(!in[x])	que.push(x);
		}
	}
	cout << ans << '\n';
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