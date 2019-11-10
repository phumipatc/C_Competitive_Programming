/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[210][210],dp[210][210];
int main(){
    int r,c,ans;
    scanf("%d %d",&r,&c);
    for(int i=1;i<=r;i++)
        for(int j=1;j<=c;j++)
            scanf("%d",&a[i][j]);
    for(int i=r;i>=1;i--)
        for(int j=1;j<=c;j++)
            dp[i][j] = a[i][j] + max(dp[i+1][j],dp[i][j-1]);
    ans = dp[1][c];
    for(int i=r-1;i>=1;i--)
        dp[i][1] = a[i][1] + dp[i+1][1];
    for(int j=1;j<=c;j++)
        dp[r][j] = a[r][j] + dp[r][j-1];
    for(int i=r-1;i>=1;i--)
        for(int j=2;j<=c;j++)
            dp[i][j] = a[i][j] + min(dp[i+1][j],dp[i][j-1]);
    printf("%d\n",ans-dp[1][c]);
	return 0;
}
