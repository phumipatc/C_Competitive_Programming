/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
long long a[10100],dp[10100][10100];
int main(){
    long long n,k,now = 1,ans = 0;
    scanf("%lld %lld",&n,&k);
    dp[0][0]=1;
    for(long long i=1;i<=n;i++){
        dp[i][0] = dp[i][i] = 1;
        for(long long j=1;j<i;j++)
            dp[i][j] = (dp[i-1][j-1] + dp[i-1][j])%1000000007;
    }
    for(long long i=0;i<n;i++)
        scanf("%lld",&a[i]);
    sort(a,a+n);
    for(long long i=k-1;i<n;i++)
        ans = (ans+(a[i]*dp[i][k-1]))%MOD;
    printf("%lld\n",ans);
	return 0;
}
