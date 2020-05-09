/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
#define MOD (LL )(1e9+7)
using namespace std;
typedef long long LL;
LL qs[100010][110],dp[110];
void solve(LL l,LL r,LL k){
	for(LL i=0;i<=k;i++)
		dp[i] = qs[r][i];
	for(LL i=1;i<=k;i++){
		for(LL j=1;j<=i;j++){
			// printf("%d %d\n",dp[i-j],qs[l-1][j]);
			dp[i]-=dp[i-j]*qs[l-1][j];
			dp[i]%=MOD;	dp[i]+=MOD;	dp[i]%=MOD;
		}
	}
	cout << dp[k] << '\n';
}
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	LL n,q,num,l,r,k;
	cin >> n >> q;
	qs[0][0] = 1;
	for(LL i=1;i<=n;i++){
		cin >> num;
		for(LL j=100;j>=num;j--)
			qs[i][j] = qs[i-1][j]+qs[i-1][j-num],qs[i][j]%=MOD;
		for(LL j=num-1;j>=0;j--)
			qs[i][j] = qs[i-1][j];
	}
	while(q--){
		cin >> l >> r >> k;
		solve(l,r,k);
	}
	return 0;
}