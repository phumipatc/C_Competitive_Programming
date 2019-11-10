/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[1510][1510],dp[1510][1510][5];
//0 Up-Left
//1 Up-Right
//2 Bottom-Left
//3 Bottom-Right
int main(){
    int n,m,K;
    scanf("%d %d %d",&n,&m,&K);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&a[i][j]);
            a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
        }
    }
    for(int i=n;i>=K;i--)
        for(int j=m;j>=K;j--)
            a[i][j] = a[i][j]-a[i-K][j]-a[i][j-K]+a[i-K][j-K];

    for(int i=K;i<=n;i++)
        for(int j=K;j<=m;j++)
            dp[i][j][0] = max(a[i][j],max(dp[i-1][j][0],dp[i][j-1][0]));
    for(int i=K;i<=n;i++)
        for(int j=m;j>=K;j--)
            dp[i][j][1] = max(a[i][j],max(dp[i-1][j][1],dp[i][j+1][1]));
    for(int i=n;i>=K;i--)
        for(int j=K;j<=m;j++)
            dp[i][j][2] = max(a[i][j],max(dp[i+1][j][2],dp[i][j-1][2]));
    for(int i=n;i>=K;i--)
        for(int j=m;j>=K;j--)
            dp[i][j][3] = max(a[i][j],max(dp[i+1][j][3],dp[i][j+1][3]));

    int ans = 0;
    for(int i=K;i<=n-K;i++)
        for(int j=K;j<=m-K;j++)
            ans = max(ans,dp[i][j][0]+dp[i][j+K][1]+dp[i+K][m][2]);
    for(int i=K;i<=n-K;i++)
        for(int j=2*K;j<=m;j++)
            ans = max(ans,dp[i][j][1]+dp[i+K][j][3]+dp[n][j-K][0]);
    for(int i=2*K;i<=n;i++)
        for(int j=K;j<=m-K;j++)
            ans = max(ans,dp[i][j][2]+dp[i][j+K][3]+dp[i-K][m][0]);
    for(int i=K;i<=n-K;i++)
        for(int j=K;j<=m-K;j++)
            ans = max(ans,dp[i][j][0]+dp[i+K][j][2]+dp[n][j+K][1]);
    for(int i=K;i<=n;i++)
        for(int j=2*K;j<=m-K;j++)
            ans = max(ans,a[i][j]+dp[n][j-K][0]+dp[n][j+K][1]);
    for(int i=2*K;i<=n-K;i++)
        for(int j=K;j<=m;j++)
            ans = max(ans,a[i][j]+dp[i-K][m][0]+dp[i+K][m][2]);
    printf("%d\n",ans);
    // for(int i=K;i<=n;i++){
    //     for(int j=K;j<=m;j++){
    //         for(int k=1;k<=3;k++){
    //             int sum = a[i][j]-a[i-K][j]-a[i][j-K]+a[i-K][j-K];
    //             dp[i][j][k] = max(sum+dp[i-K][j][k-1],max(sum+dp[i][j-K][k-1],max(dp[i-1][j][k],dp[i][j-1][k])));
    //         }
    //     }
    // }
    // printf("%d\n",dp[n][m][3]);
	return 0;
}