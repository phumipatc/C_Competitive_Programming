/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
long long dp[10005][10005],a[10505];
int main()
{
    long long i,j,n;
    dp[1][0]=1;
    scanf("%lld",&n);
    for(i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    if(a[1]>0){
        printf("0\n");
        return 0;
    }
    for(i=2;i<=n;i++){
        if(a[i] == -1){
            dp[i][0] = dp[i-1][0]+dp[i-1][1];
            dp[i][0]%=MOD;
            for(j=1;j<=i;j++){
                dp[i][j] = dp[i-1][j]+dp[i-1][j+1]+dp[i-1][j-1];
                dp[i][j]%=MOD;
            }
        }else{
            dp[i][a[i]] = dp[i-1][a[i]]+dp[i-1][a[i]+1];
            if(a[i])	dp[i][a[i]]+=dp[i-1][a[i]-1];
            dp[i][a[i]]%=MOD;;
        }
    }
    printf("%lld\n",dp[n][0]);
    return 0;
}


