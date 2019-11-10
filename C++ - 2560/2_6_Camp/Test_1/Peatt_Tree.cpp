/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
#define MOD 9973
using namespace std;
int dp[1005];
int gen(int n){
    if(dp[n]!=-1)           return dp[n];
    if(n == 0 || n == 1)    return dp[n] = 1;
    int a,b,sum = 0;
    for(int i=0;i<n;i++){
        a = gen(i)%MOD;
        b = gen(n-i-1)%MOD;
        sum+=(a*b);
        sum%=MOD;
    }
    return dp[n] = sum%MOD;
}
int main(){
    int q,n;
    cin >> q;
    memset(dp,-1,sizeof dp);
    n = gen(1000);
    while(q--){
        cin >> n;
        n--;
        cout << dp[n]%MOD << endl;
    }
    return 0;
}
