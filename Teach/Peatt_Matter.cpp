/*
	Task	: Peatt_Matter
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 16 May 2021 [20:49]
	Algo	: 
	Status	: 
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
const int N = 110;
int dp[30010][N],a[N];
void solve(){
	memset(dp,0,sizeof dp);
	int n,sum = 0;
	cin >> n;
	rep(i,1,n+1)
		cin >> a[i],a[i]+=101;
	sum = accumulate(a+1,a+n+1,0);
	dp[0][0] = 1;
	rep(i,1,n+1){
		for(int j=sum/2;j>=a[i];j--)
			rep(k,1,n/2+1)
				if(dp[j-a[i]][k-1])
					dp[j][k] = 1;
	}
	int ans = sum;
	rep(i,0,sum/2+1){
		if(!dp[i][n/2])	continue;
		ans = min(ans,abs(i-(sum-i)));
	}
	cout << ans << '\n';
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