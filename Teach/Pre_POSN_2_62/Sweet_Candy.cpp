/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int dp[5010];
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int n,m,d,s;
	cin >> n >> m;
	memset(dp,-1,sizeof dp);
	dp[0] = 0;
	while(n--){
		cin >> d >> s;
		for(int i=m;i>=s;i--){
			if(dp[i-s] == -1)	continue;
			dp[i] = max(dp[i],dp[i-s]+d);
		}
	}
	int maxx = 0;
	for(int i=1;i<=m;i++)
		maxx = max(maxx,dp[i]);
	cout << maxx << '\n';
	return 0;
}