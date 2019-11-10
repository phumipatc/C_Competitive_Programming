/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int dp[5010][5010],qs[5010],maxx[5010];
int main(){
    int n,k,ans = 0;
    scanf("%d %d",&n,&k);
    for(int i=0;i<=k;i++)
        maxx[i] = -1e9;
    for(int i=0;i<=n;i++)
        for(int j=1;j<=k;j++)
            dp[i][j] = -1e9;
    maxx[0] = 0;
    for(int i=1;i<=n;i++){
        scanf("%d",&qs[i]);
        qs[i]+=qs[i-1];
        for(int j=1;j<=k;j++){
            dp[i][j] = maxx[j-1]+qs[i];
            dp[i][j] = max(dp[i][j],dp[i-1][j]);
            // printf("%d %d %d\n",i,j,dp[i][j]);
            ans = max(ans,dp[i][j]);
        }
        for(int j=0;j<k;j++)
            maxx[j] = max(maxx[j],dp[i-1][j]-qs[i]);
    }
    printf("%d\n",ans);
	return 0;
}