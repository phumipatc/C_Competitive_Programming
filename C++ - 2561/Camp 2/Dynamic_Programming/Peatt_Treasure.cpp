/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int dp[310][310][310],a[310][310];
int main(){
    int q,r,c,ans;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&r,&c);
        for(int i=1;i<=r;i++)
            for(int j=1;j<=c;j++)
                scanf("%d",&a[i][j]);
        for(int i=1;i<=r+1;i++)
            for(int j=0;j<=c+1;j++)
                for(int k=0;k<=c+1;k++)
                    dp[i][j][k] = -1e9;
        for(int i=1;i<=r;i++){
            for(int j=1;j<=c;j++){
                for(int k=1;k<=c;k++){
                    for(int n=-1;n<=1;n++)
                        for(int m=-1;m<=1;m++)
                            dp[i][j][k] = max(dp[i][j][k],dp[i-1][j+n][k+m]);
                    if(j == k)  dp[i][j][k]+=a[i][j];
                    else        dp[i][j][k]+=a[i][j]+a[i][k];
                }
            }
        }
        ans = -1e9;
        for(int j=1;j<=c;j++)
            ans = max(ans,dp[r][j][j]);
        printf("%d\n",ans);
    }
	return 0;
}
