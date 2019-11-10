/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int a[1001][1001],dp[1001][1001];
int main(){
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin >> a[i][j];
    dp[0][1] = 1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j]) continue;
            dp[i][j] = (dp[i-1][j]+dp[i][j-1])%MOD;
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}
