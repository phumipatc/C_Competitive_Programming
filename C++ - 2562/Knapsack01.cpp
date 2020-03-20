/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int dp[10010];
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int n,m,p,w;
	cin >> n >> m;
	for(int i=1;i<=m;i++)
		dp[i] = -1;
	for(int i=1;i<=n;i++){
		cin >> p >> w;
		for(int j=m;j>=w;j--){
			if(dp[j-w] == -1)	continue;
			dp[j] = max(dp[j],dp[j-w]+p);
		}
	}
	int ans = 0;
	for(int i=1;i<=m;i++)
		ans = max(ans,dp[i]);
	cout << ans << '\n';
	return 0;
}