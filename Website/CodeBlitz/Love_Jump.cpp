/*
	Task	: Love_Jump
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 23 December 2022 [21:27]
	Algo	: QS2D
	Status	: Finished
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
const int N = 1e3+10;
int dp[N][N];
void init(){
	
}
void solve(){
	int n,m,q;
	cin >> n >> m >> q;
	rep(i,1,n){
		rep(j,1,m){
			cin >> dp[i][j];
			dp[i][j]+=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
		}
	}
	while(q--){
		int a,b,c,d,have;
		cin >> a >> b >> c >> d >> have;
		a++,b++,c++,d++;
		int sum = dp[c][d]-dp[a-1][d]-dp[c][b-1]+dp[a-1][b-1];
		cout << (have>=sum?"Y":"N") << '\n';
	}
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	freopen("d:/Code/C_Programming/input.in","r",stdin);
	init();
	int q = 1;
	// cin >> q;
	for(int Q=1;Q<=q;Q++){
		// cout << "Case #" << Q << ": ";
		solve();
	}
	return 0;
}