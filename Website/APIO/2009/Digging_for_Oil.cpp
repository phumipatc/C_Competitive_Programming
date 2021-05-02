/*
	Task	: Digging_for_Oil
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Created	: 30 April 2021 [17:05]
	Algo	: DP + Observe
	Status	: Finished
*/
#include<bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < (b); ++i)
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
	if(b == 0)	return 1;
	if(b == 1)	return a%c;
	LL now = modN(a,b/2,c);
	if(b&1)	return (((now*now)%c)*(a%c))%c;
	else	return (now*now)%c;
}
int qs[1510][1510],dp[4][1510][1510];
//0-upleft	1-upright	2-downleft	3-downright
int k;
int sum(int x,int y){
	return qs[x][y] - qs[x-k][y] - qs[x][y-k] + qs[x-k][y-k];
}
void solve(){
	int n,m;
	cin >> n >> m >> k;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin >> qs[i][j],qs[i][j]+=qs[i-1][j]+qs[i][j-1]-qs[i-1][j-1];
	for(int i=k;i<=n;i++){
		for(int j=k;j<=m;j++)
			dp[0][i][j] = max({dp[0][i-1][j],dp[0][i][j-1],sum(i,j)});
		for(int j=m;j>=k;j--)
			dp[1][i][j-k+1] = max({dp[1][i-1][j-k+1],dp[1][i][j-k+2],sum(i,j)});
	}
	for(int i=n;i>=k;i--){
		for(int j=k;j<=m;j++)
			dp[2][i-k+1][j] = max({dp[2][i-k+2][j],dp[2][i-k+1][j-1],sum(i,j)});
		for(int j=m;j>=k;j--)
			dp[3][i-k+1][j-k+1] = max({dp[3][i-k+2][j-k+1],dp[3][i-k+1][j-k+2],sum(i,j)});
	}
	int ans = 0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			ans = max({ans,dp[0][i][m] + dp[2][i+1][j] + dp[3][i+1][j+1],
							dp[2][i+1][m] + dp[0][i][j] + dp[1][i][j+1],
							dp[0][i][j] + dp[2][i+1][j] + dp[1][n][j+1],
							dp[0][n][j] + dp[1][i][j+1] + dp[3][i+1][j+1]});
	for(int i=k;i<=n;i++)
		for(int j=k;j<=m;j++)
			ans = max({ans,sum(i,j) + dp[0][n][j-k] + dp[1][n][j+1],
							sum(i,j) + dp[0][i-k][m] + dp[2][i+1][m]});
	cout << ans << '\n';
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int q = 1;
	// cin >> q;
	for(int Q=1;Q<=q;Q++){
		// cout << "Case #" << Q << ": ";
		solve();
	}
	return 0;
}