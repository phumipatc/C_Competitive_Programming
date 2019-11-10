/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long dp[1005][1005][10],a[1005][5];
int main()
{
    long long n,k,i,j,l,ans=-1e18;
    scanf("%lld %lld",&n,&k);
    for(i=1;i<=n;i++)
        for(j=1;j<=3;j++)
            scanf("%lld",&a[i][j]);
    for(i=0;i<=n;i++)
        for(j=1;j<=k;j++)
            for(l=0;l<=7;l++)
                dp[i][j][l] = -1e18;
    for(i=1;i<=n;i++){
        for(j=1;j<=k;j++){
            dp[i][j][0] = dp[i-1][j][7];
            if(i>1){
                dp[i][j][1] = max(dp[i][j][0],dp[i-1][j-1][6] + a[i][3] + a[i-1][3]);
                dp[i][j][2] = max(dp[i][j][0],dp[i-1][j-1][5] + a[i][2] + a[i-1][2]);
                dp[i][j][4] = max(dp[i][j][0],dp[i-1][j-1][3] + a[i][1] + a[i-1][1]);
            }
            dp[i][j][1] = max(dp[i][j][0],dp[i][j][1]);
            dp[i][j][2] = max(dp[i][j][0],dp[i][j][2]);
            dp[i][j][4] = max(dp[i][j][0],dp[i][j][4]);
            dp[i][j][3] = max(dp[i][j][0],max(dp[i-1][j-1][7] + a[i][2] + a[i][3],max(dp[i][j][1],dp[i][j][2])));
            dp[i][j][6] = max(dp[i][j][0],max(dp[i-1][j-1][7] + a[i][1] + a[i][2],max(dp[i][j][4],dp[i][j][2])));
            if(i>1 && j >= 2)
                dp[i][j][5] = max(dp[i][j][0],max(dp[i-1][j-2][2] + a[i][1] + a[i][3] + a[i-1][1] + a[i-1][3],max(dp[i][j][1],dp[i][j][4])));
            dp[i][j][5] = max(dp[i][j][0],dp[i][j][5]);
            if(i>1 && j>=2)
                dp[i][j][7] = max(dp[i-1][j-2][3] + a[i-1][1] + a[i][1] + a[i][2] + a[i][3],dp[i-1][j-2][6] + a[i-1][3] + a[i][1] + a[i][2] + a[i][3]);
            if(i>1&& j>=3)
                dp[i][j][7] = max(dp[i][j][7],dp[i-1][j-3][0] + a[i-1][1] + a[i-1][2] + a[i-1][3] + a[i][1] + a[i][2] + a[i][3]);
            for(l=0;l<=6;l++){
                dp[i][j][7] = max(dp[i][j][7],dp[i][j][l]);
            }
        }
    }
    for(l=0;l<=7;l++)
        ans = max(ans,dp[n][k][l]);
    printf("%lld\n",ans);
}
/*
3
1 2 3
2 3 4
3 4 8
*/
