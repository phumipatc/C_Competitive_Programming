/*
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int a[1010],dp[1010][55];
int main(){
    ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
    int n,x,y,z;
    cin >> n >> x >> y >> z;
    for(int i=1;i<=n;i++)
        cin >> a[i];
    for(int i=0;i<=n;i++)
        for(int j=0;j<=50;j++)
            dp[i][j] = 1e9;
    dp[0][0] = 0;
    for(int i=1;i<=n;i++){
        for(int j=a[i];j<=50;j++){
            for(int k=0;k<=j;k++)
                dp[i][j] = min(dp[i][j],dp[i-1][k]+(j-k)*x);
            for(int k=j+1;k<=50;k++)
                dp[i][j] = min(dp[i][j],dp[i-1][k]+(k-j)*z);
            dp[i][j]+=j*y;
        }
    }
    int ans = 1e9;
    for(int i=a[n];i<=50;i++)
        ans = min(ans,dp[n][i]);
    cout << ans << '\n';
    return 0;
}