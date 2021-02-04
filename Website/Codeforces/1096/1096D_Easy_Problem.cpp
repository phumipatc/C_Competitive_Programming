/*
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
char a[100010];
long long dp[100010][4];
int main()
{
    long long n,num,minn = 1e18;
    scanf("%lld %s",&n,a+1);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&num);
        for(int j=0;j<4;j++)
            dp[i][j] = dp[i-1][j];
        if(a[i] == 'h')
            dp[i][0] = dp[i-1][0]+num;
        else if(a[i] == 'a')
            dp[i][1] = min(dp[i-1][1]+num,dp[i-1][0]);
        else if(a[i] == 'r')
            dp[i][2] = min(dp[i-1][2]+num,min(dp[i-1][1],dp[i-1][0]));
        else if(a[i] == 'd')
            dp[i][3] = min(dp[i-1][3]+num,min(dp[i-1][2],min(dp[i-1][1],dp[i-1][0])));
    }
    for(int i=0;i<4;i++)
        minn = min(minn,dp[n][i]);
    printf("%lld\n",minn);
    return 0;
}