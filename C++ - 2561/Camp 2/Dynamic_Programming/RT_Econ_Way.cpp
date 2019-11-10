/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[210][210],dp[210][210];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            dp[i][j] = max(dp[i-1][j-1]+a[i][j],max(dp[i-1][j],dp[i][j-1]));
    printf("%d\n",dp[n][n]);
	return 0;
}
