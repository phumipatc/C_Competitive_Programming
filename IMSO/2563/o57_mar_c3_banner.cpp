/*
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Algo	: Divide & Conquer
	Status	: Finsihed
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
int dp[310][310],a[310][310];
int divide(int l,int r){
	if(dp[l][r]!=-1)	return dp[l][r];
	int maxx = 0;
	for(int i=l;i<r;i++)
		maxx = max(maxx,a[l][r]+divide(l,i)+divide(i+1,r));
	return dp[l][r] = maxx;
}
void solve(){
	int n,m,l,r;
	cin >> n >> m;
	for(int i=1;i<=m;i++){
		cin >> l >> r;
		a[l][r]++;
	}
	memset(dp,-1,sizeof dp);
	cout << m-divide(1,n);
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