/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
#define MOD 909091
using namespace std;
long long dp[10010];
long long catalan(long long n){
    if(n == 0)  return dp[0] = 1;
    if(n == 1)  return dp[1] = 1;
    if(dp[n])   return dp[n];
    long long sum = 0;
    for(long long i=0;i<n;i++)    sum = (sum+(catalan(i)%MOD)*(catalan(n-i-1)%MOD))%MOD;
    return dp[n] = (sum)%MOD;
}
int main(){
    long long n;
    n = catalan(10000);
    scanf("%lld",&n);
    printf("%lld\n",dp[n]);
	return 0;
}
