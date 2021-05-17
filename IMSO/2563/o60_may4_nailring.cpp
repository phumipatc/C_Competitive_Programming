/*
	Task	: o60_may4_nailring
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 17 May 2021 [15:39]
	Algo	: DP
	Status	: Finished
*/
#include<bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i <= (b); ++i)
#define repr(i, a, b) for(int i = a; i >= (b); --i)
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
const int N = 5010;
LL dp[N][N];
char a[N];
void solve(){
	int n;
	LL k;
	cin >> a+1 >> k;
	n = strlen(a+1);
	dp[n][1] = 1;
	repr(i,n-1,1){
		rep(j,0,i){
			if(j>0 && a[i]!='(')	dp[i][j]+=dp[i+1][j-1];
			if(a[i]!=')')			dp[i][j]+=dp[i+1][j+1];
			dp[i][j] = min(dp[i][j],(LL )1e18);
		}
	}
	int state = 0;
	k--;
	rep(i,1,n){
		if(a[i] == '.'){
			if(k<dp[i+1][state+1])	cout << '(',state++;
			else					cout << ')',k-=dp[i+1][state+1],state--;
		}else{
			state+=(a[i] == '('?1:-1);
			cout << a[i];
		}
	}
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