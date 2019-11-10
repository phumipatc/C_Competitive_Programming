/*
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int dp[110][110][110];
int main(){
    ios_base::sync_with_stdio(0);	cin.tie(0);
    int m,k,w,v,t;
    cin >> m >> k;
    for(int i=0;i<=m;i++)
        for(int j=0;j<=k;j++)
            for(int l=0;l<=k;l++)
                dp[i][j][l] = -1e9;
    dp[0][0][0] = 0;
    for(int i=1;i<=k;i++){
        cin >> w >> v >> t;
        for(int i=m-w;i>=0;i--){
            for(int j=k;j>=0;j--){
                for(int l=k;l>=0;l--){
                    if(dp[i][j][l]<0)   continue;
                    if(t == 1)  dp[i+w][j+1][l] = max(dp[i+w][j+1][l],dp[i][j][l]+v);
                    else        dp[i+w][j][l+1] = max(dp[i+w][j][l+1],dp[i][j][l]+v);
                }
            }
        }
    }
    int maxx = 0;
    for(int i=0;i<=m;i++){
        for(int j=0;j<=k;j++){
            for(int l=max(0,(j-1)/2);l<=min(k,2*(j+1));l++){
                maxx = max(maxx,dp[i][j][l]);
            }
        }
    }
    printf("%d\n",maxx);
    return 0;
}