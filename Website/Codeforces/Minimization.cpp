/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int a[300010],dp[5010][5010];
void solve(){
	int n,k;
	cin >> n >> k;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	sort(a+1,a+n+1);
	for(int i=0;i<=k;i++)
		for(int j=0;j<=k;j++)
			dp[i][j] = 1e9;
	
}
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	solve();
	return 0;
}