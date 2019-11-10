/*
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
int dp[2010][2010];
int qs[2][2010];
int a[2][2010];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin >> n;
    dp[0][0] = 1;
    for(int i=1;i<=n;i++){
        cin >> a[0][i];
        qs[0][i] = qs[0][i-1]+a[0][i];
        dp[i][0] = qs[0][i]>=0 && dp[i-1][0];
    }
    cin >> m;
    for(int i=1;i<=m;i++){
        cin >> a[1][i];
        qs[1][i] = qs[1][i-1]+a[1][i];
        dp[0][i] = qs[1][i]>=0 && dp[0][i-1];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(qs[0][i]+qs[1][j]<0) continue;
            dp[i][j] = (dp[i-1][j]+dp[i][j-1])%mod;
        }
    }
    printf("%d\n",dp[n][m]);
    return 0;
}
