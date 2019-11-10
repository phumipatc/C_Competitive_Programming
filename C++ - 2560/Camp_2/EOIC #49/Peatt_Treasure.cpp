/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
#define INF 100000000
using namespace std;
long long a[310][310],dp[310][310][310];
int main()
{
    long long i,j,k,n,q,r,c,mx;
    scanf("%lld",&q);
    while(q--){
        scanf("%lld %lld",&r,&c);
        for(i=1;i<310;i++)
            for(j=0;j<310;j++)
                for(k=0;k<310;k++)
                    dp[i][j][k]=-INF;
        for(i=1;i<=r;i++){
            for(j=1;j<=c;j++){
                scanf("%lld",&a[i][j]);
            }
        }

        for(i=1;i<=r;i++){
            for(j=1;j<=c;j++){
                for(k=1;k<=c;k++){
                    mx = dp[i-1][j][k];
                    mx = max(mx,max(dp[i-1][j-1][k],dp[i-1][j+1][k]));
                    mx = max(mx,max(dp[i-1][j-1][k-1],dp[i-1][j+1][k-1]));
                    mx = max(mx,max(dp[i-1][j][k-1],dp[i-1][j+1][k+1]));
                    mx = max(mx,max(dp[i-1][j-1][k+1],dp[i-1][j][k+1]));
                    if(j==k)    dp[i][j][k] = mx+a[i][j];
                    else        dp[i][j][k] = mx+a[i][j]+a[i][k];
                }
            }
        }
        for(i=1,mx=dp[r][1][1];i<=c;i++){
            mx=max(mx,dp[r][i][i]);
        }
        printf("%lld\n",mx);
    }
    return 0;
}
/*
1
6 5
8 7 4 3 4
-8 -1 -3 -2 -5
2 8 7 1 1
3 -4 -1 -7 3
-4 -3 8 7 4
6 4 -3 -2 -1
*/
