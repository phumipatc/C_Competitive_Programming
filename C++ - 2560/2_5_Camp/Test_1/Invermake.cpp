/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
#define Mod 1000000007
using namespace std;
long long dp[1010][10005];
int main()
{
    int n,m;
    cin >> n >> m;
    dp[1][0] = 1;
    for(int i = 2; i<=n; i++){
        for(int j = 0; j<=m; j++){
            if(j == 0)  dp[i][j] = 1;
            else
            {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
                if(j-i>=0)  dp[i][j] -= dp[i-1][j-i];
                dp[i][j] = ((dp[i][j]%Mod)+Mod)%Mod;
            }
        }
    }
    cout << dp[n][m];
    return 0;
}
