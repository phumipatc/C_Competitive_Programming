/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long dp[110005];
#define mod 1000000007
long long play(long long n,long long k)
{
    long long sum=1;
    for(long long i=1;i<=n+1;i++){
        dp[i]=sum;
        dp[i]=(dp[i]+mod)%mod;
        sum+=dp[i];
        sum=(sum+mod)%mod;
        if(i-k-1>=0)    sum-=dp[i-k-1];
    }
    long long t=dp[n+1];
    t=(t+mod)%mod;
    memset(dp,0,sizeof dp);
    dp[0]=1;
    return t;
}
int main()
{
    long long j,n,i,k,ans,sum=1;
    scanf("%lld %lld",&n,&k);
    if(k==0){
        printf("1\n");
        return 0;
    }
    dp[0]=1;
    ans=play(n,k);
    ans=(ans+mod)%mod;
    ans-=play(n,k-1);
    ans=(ans+mod)%mod;
    printf("%lld",ans);
    return 0;
}

