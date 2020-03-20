/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
#define MOD 2009
using namespace std;
typedef long long LL;
int dp[100010];
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int n,k;
	cin >> n >> k;
	dp[0] = 1;
	for(int i=1;i<=n;i++){
		dp[i] = dp[i-1];
		if(i>k)	dp[i]-=dp[i-k-1];
		dp[i]%=MOD,dp[i]+=MOD,dp[i]%=MOD;
		// printf("%d\n",dp[i]);
		dp[i]+=dp[i-1];
		dp[i]%=MOD;
	}
	cout << (((dp[n]-dp[n-1])%MOD)+MOD)%MOD << '\n';
	return 0;
}