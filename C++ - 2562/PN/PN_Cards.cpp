/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int a[5010],b[5010];
int dp[2][5010];
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int q,n,m;
	cin >> q;
	while(q--){
		cin >> n >> m;
		for(int i=1;i<=n;i++)
			cin >> a[i];
		for(int i=1;i<=m;i++)
			cin >> b[i];
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				dp[i%2][j] = max(abs(a[i]-b[j])+dp[!(i%2)][j-1],max(dp[!(i%2)][j],dp[i%2][j-1]));
		cout << dp[n%2][m];
	}
	return 0;
}