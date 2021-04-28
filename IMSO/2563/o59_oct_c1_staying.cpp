/*
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Algo	:
	Status	:
*/
#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define allst(x,y) (x).begin()+y,(x).end()
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
LL minN(vector<LL > a){
	LL minn = 1e18;
	for(auto x:a)
		minn = min(minn,x);
	return minn;
}
LL maxN(vector<LL > a){
	LL maxx = -1e18;
	for(auto x:a)
		maxx = max(maxx,x);
	return maxx;
}
LL modN(LL a,LL b,LL c = MOD){
	if(b == 0)	return 1;
	if(b == 1)	return a%c;
	LL now = modN(a,b/2);
	if(b&1)	return (((now*now)%c)*(a%c))%c;
	else	return (now*now)%c;
}
LL dp[1010][3][1010][8];
void solve(){
	int n,ka,kb,kc;
	cin >> n >> ka >> kb >> kc;
	dp[1][0][1][1] = 1;
	for(int i=2;i<=n;i++){
		for(int k=1;k<8;k++){
			//a from a
			for(int j=1;j<=ka;j++)
				dp[i][0][j][k|1]+=dp[i-1][0][j-1][k],dp[i][0][j][k|1]%=MOD;
			//a from c
			for(int j=1;j<=kc;j++)
				dp[i][0][1][k|1]+=dp[i-1][2][j][k],dp[i][0][1][k|1]%=MOD;

			//b from a
			for(int j=1;j<=ka;j++)
				dp[i][1][1][k|2]+=dp[i-1][0][j][k],dp[i][1][1][k|2]%=MOD;
			//b from b
			for(int j=1;j<=kb;j++)
				dp[i][1][j][k|2]+=dp[i-1][1][j-1][k],dp[i][1][j][k|2]%=MOD;

			//c from a
			for(int j=1;j<=ka;j++)
				dp[i][2][1][k|4]+=dp[i-1][0][j][k],dp[i][2][1][k|4]%=MOD;
			//c from b
			for(int j=1;j<=kb;j++)
				dp[i][2][1][k|4]+=dp[i-1][1][j][k],dp[i][2][1][k|4]%=MOD;
			//c from c
			for(int j=1;j<=kc;j++)
				dp[i][2][j][k|4]+=dp[i-1][2][j-1][k],dp[i][2][j][k|4]%=MOD;
		}
	}
	LL ans = 0;
	for(int j=1;j<=ka;j++)
		ans+=dp[n][0][j][7],ans%=MOD;
	for(int j=1;j<=kb;j++)
		ans+=dp[n][1][j][7],ans%=MOD;
	for(int j=1;j<=kc;j++)
		ans+=dp[n][2][j][7],ans%=MOD;
	cout << ans << '\n';
}
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int q = 1;
	// cin >> q;
	while(q--){
		solve();
	}
	return 0;
}