/*
	Task	: PN_Stock
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 16 May 2021 [14:42]
	Algo	: DP
	Status	: Untest
*/
#include<bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x),end(x)
#define allst(x,y) (x).begin()+y,(x).end()
#define rmdup(x) (x).resize(unique((x).begin(),(x).end())-(x).begin())
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
const int N = 1000010;
LL dp[N][4];
void solve(){
	int n,num;
	cin >> n;
	rep(i,0,n+1)	rep(j,0,4)	dp[i][j] = -1e18;
	rep(i,1,n+1){
		cin >> num;
		dp[i][0] = max(dp[i-1][0],(LL )-num);
		dp[i][1] = max(dp[i-1][1],dp[i-1][0]+num);
		dp[i][2] = max(dp[i-1][2],dp[i-1][1]-num);
		dp[i][3] = max(dp[i-1][3],dp[i-1][2]+num);
	}
	LL ans = -1e18;
	rep(i,0,4)	ans = max(ans,dp[n][i]);
	cout << max(ans,0ll) << '\n';
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