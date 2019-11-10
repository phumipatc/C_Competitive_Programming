/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
long long dp[100100],dp2[100100];
int main(){
    long long n,i,j;
    scanf("%lld",&n);
    dp[2]=dp2[2]=1;
    for(i=3;i<=100000;i++){
        dp[i]=(i-1)*dp2[i-1];
        dp[i]%=MOD;
        dp2[i]=dp[i]+dp[i-1];
        dp2[i]%=MOD;
    }
    printf("%lld\n",dp[n]);
    return 0;
}
