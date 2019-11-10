/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int dp[4][150005];
int main()
{
    int n,v,ans=1e9;
    scanf("%d",&n);
    for(int i=1;i<=3;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&dp[i][j]);
            dp[i][j]+=dp[i][j-1];
        }
    }
    for(int i=1;i<=3;i++){
        for(int j=1;j<=3;j++){
            if(i==j)    continue;
            v=dp[i][1]-dp[j][1];
            for(int k=2;k<n;k++){
                ans=min(ans,dp[j][k]+v+dp[6-i-j][n]-dp[6-i-j][k]);
                v=min(v,dp[i][k]-dp[j][k]);
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
/*
7
3 3 4 1 3 4 4
4 2 5 1 5 5 4
5 5 1 3 4 4 4
*/
