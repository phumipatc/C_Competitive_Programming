/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[100005],qs[100005],dp[100005][105];
int main(){
    int n,k,p;
    cin >> n >> k >> p;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        qs[i] = a[i]+qs[i-1];
    }
    if(k*p>n){
        cout << qs[n];
        return 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            if(j == 1 && i-p>=0)    dp[i][j] = qs[i]-qs[i-p];
            else if(i-p>=0)         dp[i][j] = qs[i]-qs[i-p]+dp[i-p][j-1];
            dp[i][j] = max(dp[i][j],dp[i-1][j]);
        }
    }
    cout << dp[n][k];
    return 0;
}
