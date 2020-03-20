/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int dp[150010],v[5010];
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int n,k,num,ans = 0;
	cin >> n >> k;
	memset(dp,-1,sizeof dp);
	dp[0] = 0;
	for(int i=1;i<=n;i++)
		cin >> v[i];
	for(int i=1;i<=n;i++){
		cin >> num;
		num++;
		num*=8;
		for(int j=k;j>=num;j--){
			if(dp[j-num] == -1)	continue;
			dp[j] = max(dp[j],dp[j-num]+v[i]);
			ans = max(ans,dp[j]);
		}
	}
	cout << ans << '\n';
	return 0;
}