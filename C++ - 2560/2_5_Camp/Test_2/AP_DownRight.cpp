/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long dp[1005][1005][5],a[1005][1005];
int main(){
    long long q,r,c;
    scanf("%lld",&q);
    while(q--){
        scanf("%lld %lld",&r,&c);
        for(long long i=1;i<=r;i++)
            for(long long j=1;j<=c;j++)
                scanf("%lld",&a[i][j]);
        memset(dp,0,sizeof dp);
        for(long long i=1;i<=r;i++){
            for(long long j=1;j<=c;j++){
                for(long long k=0;k<3;k++)
                    dp[i][j][0]=max(dp[i][j][0],max(dp[i-1][j][k],dp[i][j-1][k]));
                dp[i][j][1] = a[i][j]+max(dp[i-1][j][0],dp[i][j-1][0]);
                dp[i][j][2] = a[i][j]+max(dp[i-1][j][1],dp[i][j-1][1]);

            }
        }
        long long maxx = -1;
        for(long long i=0;i<3;i++)
            maxx = max(maxx,dp[r][c][i]);
        printf("%lld\n",maxx);
    }
    return 0;
}
