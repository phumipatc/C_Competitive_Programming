/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
long long dp[11505][11505],a[10505];
int main()
{
    long long i,j,n;
    dp[1][0]=1;
    scanf("%lld",&n);
    for(i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    for(i=1;i<=n;i++){
        if(i==n)
            dp[n][0]+=dp[n-1][0]+dp[n-1][1],dp[i][j]%=MOD;
        else if(a[i]==-1){
            for(j=0;j<=10000;j++){
                dp[i][j]+=dp[i-1][j-1]+dp[i-1][j]+dp[i-1][j+1];
                dp[i][j]%=MOD;
            }
        }else{
            dp[i][a[i]]+=dp[i-1][a[i]-1]+dp[i-1][a[i]]+dp[i-1][a[i]+1];
            dp[i][j]%=MOD;;
        }
    }
    if(a[n]==-1)
        printf("%lld\n",dp[n][0]%MOD);
    else
        printf("%lld\n",dp[n][a[n]]%MOD);
    return 0;
}


