/*
	Task	: PT_Mean_Max
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Created	: 09 May 2021 [19:12]
	Algo	:
	Status	:
*/
#include<bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x),end(x)
#define allst(x,y) (x).begin()+y,(x).end()
#define remdup(x) (x).resize(unique((x).begin(),(x).end())-(x).begin())
#define sz(x) (int)(x).size()
#define decp(x) fixed << setprecision(x)
#define MOD (LL )(1e9+7)
using namespace std;
using LL = long long;
using PII = pair<int ,int >;
using PLL = pair<long long ,long long >;
const int dir4[2][4] = {{1,-1,0,0},{0,0,1,-1}};
const int dir8[2][8] = {{-1,-1,-1,0,1,1,1,0},{-1,0,1,1,-1,0,1,-1}};
const int MAX_INT = 2e9;
const LL MAX_LL = 1e18;
LL modN(LL a,LL b,LL c = MOD){
	if(b == 0)	return 1;
	if(b == 1)	return a%c;
	LL now = modN(a,b/2,c);
	if(b&1)	return (((now*now)%c)*(a%c))%c;
	else	return (now*now)%c;
}
const int N = 300010;
double qs[N],dp[N];
void solve(){
	int n,k;
	cin >> n >> k;
	rep(i,1,n+1)
		cin >> qs[i],qs[i]+=qs[i-1];
	double l = 1,r = 1e6,mid;
	while(r-l>1e-6){
		mid = (l+r+(1e-6))/2;
		// printf("%lf %lf %lf\n",l,r,mid);
		int ch = 0;
		rep(i,1,n+1){
			dp[i] = min(dp[i-1],qs[i]-(i*mid));
			if(i>=k && qs[i]-(i*mid)-dp[i-k]>1e-6){
				ch = 1;
				break;
			}
		}
		if(ch)	l = mid;
		else	r = mid-(1e-6);
	}
	cout << decp(1) << l << '\n';
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