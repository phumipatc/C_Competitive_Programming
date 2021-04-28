/*
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Algo	:
	Status	:
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
	if(b == 0)	return 1;
	if(b == 1)	return a%c;
	LL now = modN(a,b/2);
	if(b&1)	return (((now*now)%c)*(a%c))%c;
	else	return (now*now)%c;
}
int dp[1010][1010];
void solve(){
	int n,m,t,l,r,mid;
	cin >> n >> m >> t;
	while(n--){
		cin >> l >> r,l++,r++;
		dp[l][r]++;
	}
	for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++)
			dp[i][j]+=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
	int minn = 1e9;
	for(int i=1;i<=m;i++){
		for(int j=i;j<=m;j++){
			l = 1,r = m;
			while(l<r){
				mid = (l+r)/2;
				int sum = dp[mid][j]-dp[mid][i-1];
				if(sum>=t)	r = mid;
				else		l = mid+1;
			}
			if(dp[l][j]-dp[l][i-1]>=t)
				minn = min(minn,(j-i+1)*l);
		}
	}
	cout << minn << '\n';
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