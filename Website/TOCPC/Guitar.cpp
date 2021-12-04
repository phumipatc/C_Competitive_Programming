/*
	Task	: Guitar
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 21 November 2021 [19:08]
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
const int N = 310;
int v[N][N],a[N];
LL dp[N][N];
void init(){
	
}
void solve(){
	int n,m,k;
	cin >> n >> m >> k;
	rep(i,1,n)
		rep(j,1,n)
			cin >> v[i][j];
	rep(i,1,m)
		cin >> a[i];
	fill(&dp[0][0],&dp[0][0] + sizeof(dp)/sizeof(dp[0][0]),1e18);
	dp[0][0] = 0;
	rep(i,1,m+1){
		rep(j,max(0,i-k-1),i-1){
			// lastest = j
			// doing i
			int num = i-j-1;
			rep(l,0,k-num)
				dp[i][num+l] = min(dp[i][num+l],dp[j][l] + v[a[j]][a[i]]);
		}
	}
	LL ans = 1e18;
	rep(i,0,k)
		ans = min(ans,dp[m+1][i]);
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