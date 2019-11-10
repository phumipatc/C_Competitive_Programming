/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
#define MOD (long long )1e9+7
using namespace std;
long long dp[100010];
int main(){
    dp[2] = 1;
    for(long long i=3;i<=100000;i++){
        dp[i] = dp[i-1]*i;
        dp[i]%=MOD;
        if(i%2) dp[i]--;
        else    dp[i]++;
        dp[i]+=MOD;
        dp[i]%=MOD;
    }
    long long n;
    // while(1){
    scanf("%lld",&n);
    printf("%lld\n",dp[n]);
    // }
	return 0;
}
