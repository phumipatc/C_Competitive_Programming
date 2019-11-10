/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
#define MOD 1000000007
long long dp[5000],qs[5000],way[5000];
int main()
{
    long long n;
    long long sum = 0;
    scanf(" %lld",&n);
    for(long long i = 1 ; i <= n ; i++)
        scanf(" %lld",&way[i]);
    for(long long i = 1 ; i <= n ; i++){
        dp[i] = (qs[i-1] - qs[way[i] - 1] + 2 + MOD)%MOD;
        qs[i] = (qs[i-1] + dp[i] + MOD)%MOD;
    }
    printf("%lld",(qs[n] + MOD)%MOD);
}
