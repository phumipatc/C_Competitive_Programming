/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long dp[2][5010],a[5010],b[5010];
int main(){
    long long n,m;
    scanf("%lld %lld",&n,&m);
    for(long long i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    for(long long i=1;i<=m;i++)
        scanf("%lld",&b[i]);
    for(long long i=1;i<=n;i++){
        for(long long j=1;j<=m;j++){
            dp[i%2][j] = max(dp[(i+1)%2][j-1]+abs(a[i]-b[j]),max(dp[(i+1)%2][j],dp[i%2][j-1]));
        }
    }
    printf("%lld\n",dp[n%2][m]);
	return 0;
}
