/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long a[5010],b[5010],dp[5010][5010];
int main(){
    long long n,m;
    cin >> n >> m;
    for(long long i=1;i<=n;i++)
        cin >> a[i];
    for(long long i=1;i<=m;i++)
        cin >> b[i];
    for(long long i=1;i<=n;i++)
        for(long long j=1;j<=m;j++)
            dp[i][j] = max(dp[i-1][j-1]+abs(a[i]-b[j]),max(dp[i-1][j],dp[i][j-1]));
    cout << dp[n][m] << endl;
	return 0;
}
