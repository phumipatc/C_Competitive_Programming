/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[1010][1010],dp[1010][1010][2];
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&a[i][j]);
    for(int j=1;j<=m;j++)
        dp[n][j][0] = a[n][j],dp[n][j][1] = 1;
    for(int i=n-1;i>=1;i--){
        for(int j=1;j<=m;j++){
            if(i%2 == 1){
                if(dp[i+1][j][0]+a[i][j]>dp[i][j][0]){
                    dp[i][j][0] = dp[i+1][j][0]+a[i][j];
                    dp[i][j][1] = dp[i+1][j][1];
                }
                if(dp[i+1][j-1][0]+a[i][j]>dp[i][j][0]){
                    dp[i][j][0] = dp[i+1][j-1][0]+a[i][j];
                    dp[i][j][1] = dp[i+1][j-1][1];
                }
                if(dp[i+1][j-1][0] == dp[i+1][j][0])
                    dp[i][j][1] = dp[i+1][j-1][1]+dp[i+1][j][1];
            }else{
                if(dp[i+1][j][0]+a[i][j]>dp[i][j][0]){
                    dp[i][j][0] = dp[i+1][j][0]+a[i][j];
                    dp[i][j][1] = dp[i+1][j][1];
                }
                if(dp[i+1][j+1][0]+a[i][j]>dp[i][j][0]){
                    dp[i][j][0] = dp[i+1][j+1][0]+a[i][j];
                    dp[i][j][1] = dp[i+1][j+1][1];
                }
                if(dp[i+1][j+1][0] == dp[i+1][j][0])
                    dp[i][j][1] = dp[i+1][j+1][1]+dp[i+1][j][1];
            }
        }
    }
    int ans = 0,countt = 0;
    for(int j=1;j<=m;j++){
        if(dp[1][j][0]>ans){
            ans = dp[1][j][0];
            countt = dp[1][j][1];
        }else if(dp[1][j][0] == ans)
            countt+=dp[1][j][1];
    }
    printf("%d %d\n",ans,countt);
    return 0;
}
