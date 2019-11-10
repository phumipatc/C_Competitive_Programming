/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
#define MOD 9241
using namespace std;
int dp[210][110];
int main(){
    dp[0][0] = 1;
    for(int i=0;i<=100;i++){
        for(int j=0;j<=100;j++){
            dp[i+1][j]+=dp[i][j],dp[i+1][j]%=MOD;
            dp[i+2][j]+=dp[i][j],dp[i+2][j]%=MOD;
            dp[i+2][j+1]+=dp[i][j],dp[i+2][j+1]%=MOD;
            for(int k=3;k<=100;k+=2)
                dp[i+k][j+2]+=2*dp[i][j],dp[i+k][j+2]%=MOD;
            for(int k=4;k<=100;k+=2)
                dp[i+k][j+2]+=2*dp[i][j],dp[i+k][j+2]%=MOD;
        }
    }
    int q,ans=0,n,k;
    cin >> q;
    while(q--){
        cin >> n >> k;
        ans = 0;
        for(int i=0;i<=k;i++)
            ans+=dp[n][i],ans%=MOD;
        cout << ans << endl;
    }
    return 0;
}
