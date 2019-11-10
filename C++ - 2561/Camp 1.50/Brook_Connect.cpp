/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
long long w[5000],dp[5000];
int main(){
    long long n;
    scanf(" %lld",&n);
    for(long long i=1;i<=n;i++)
        scanf(" %lld",&w[i]);
    for(long long i=1;i<=n;i++)
        dp[i] = (dp[i-1]+(dp[i-1]-dp[w[i] - 1] + 2)+MOD)%MOD;
    printf("%lld\n",dp[n]);
	return 0;
}
