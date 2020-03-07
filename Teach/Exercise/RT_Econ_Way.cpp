/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int a[210][210],dp[210][210];
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin >> a[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			dp[i][j] = max(dp[i-1][j-1]+a[i][j],max(dp[i-1][j],dp[i][j-1]));
	cout << dp[n][n] << '\n';
	return 0;
}