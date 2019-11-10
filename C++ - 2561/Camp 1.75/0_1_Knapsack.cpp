/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
int dp[110][11000];
int main()
{
    int n,m,i,j,p,w;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){
        scanf("%d %d",&p,&w);
        for(j=0;j<w;j++)
            dp[i][j] = dp[i-1][j];
        for(j=w;j<=m;j++)
            dp[i][j] = max(dp[i-1][j],p + dp[i-1][j-w]);
    }
    printf("%d\n",dp[n][m]);
    return 0;
}
