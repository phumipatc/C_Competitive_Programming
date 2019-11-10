/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
#define MOD 9241
using namespace std;
long long n,k,dp[210][110];
int main(){
    long long q,i,j;
    scanf("%lld",&q);
    dp[0][0]=1;
    for(i=0;i<=100;i++){
        for(j=0;j<=100;j++){
            dp[i+1][j]+=dp[i][j];
            dp[i+1][j]%=MOD;
            dp[i+2][j]+=dp[i][j];
            dp[i+2][j]%=MOD;
            dp[i+2][j+1]+=dp[i][j];
            dp[i+2][j+1]%=MOD;
            for(k=3;k<=100;k+=2)
                dp[i+k][j+2]+=2*dp[i][j],dp[i+k][j+2]%=MOD;
            for(k=4;k<=100;k+=2)
                dp[i+k][j+2]+=2*dp[i][j],dp[i+k][j+2]%=MOD;
        }
    }
    while(q--){
        long long sum=0;
        scanf("%lld %lld",&n,&k);
        for(i=0;i<=k;i++)   sum+=dp[n][i],sum%=MOD;
        printf("%lld\n",sum);
    }
    return 0;
}
