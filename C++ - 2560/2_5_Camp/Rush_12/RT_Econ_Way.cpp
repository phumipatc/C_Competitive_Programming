/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[205][205],dp[205][205];
int main(){
    int n,ans = -1;
    cin >> n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin >> a[i][j];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            dp[i][j] = max(dp[i-1][j-1]+a[i][j],max(dp[i-1][j],dp[i][j-1]));
    cout << dp[n][n];
    return 0;
}
