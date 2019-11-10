/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int dp[510][25][25],a[510];
int main(){
    int q,minn,n,i,j,k,ch;
    cin >> q;
    while(q--){
        cin >> n;
        ch = 0;
        for(i=1;i<=n;i++){
            cin >> a[i];
            if(a[1]!=a[i])  ch = 1;
        }
        memset(dp,0,sizeof dp);
        for(i=1;i<=n;i++){
            for(j=0;j<=20;j++){
                for(k=0;k<=20;k++){
                    dp[i][j][k] = 1e9;
                    if(j == a[i] || k == a[i]){
                        dp[i][j][k] = min(dp[i][j][k],dp[i-1][j][k]);
                    }else{
                        dp[i][j][k] = min(dp[i][j][k],dp[i-1][a[i]][k]+1);
                        dp[i][j][k] = min(dp[i][j][k],dp[i-1][j][a[i]]+1);
                    }
                }
            }
        }
        minn = 1e9;
        for(j=0;j<=20;j++)
            for(k=0;k<=20;k++)
                minn = min(minn,dp[n][j][k]);
        printf("%d\n",minn+ch+1);
    }
    return 0;
}
