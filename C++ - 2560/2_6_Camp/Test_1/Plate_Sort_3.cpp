/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
#define MOD 9871
using namespace std;
int dp[1005][1005];
int gen(int n,int k){
    if(dp[n][k]!=-1)        return dp[n][k];
    if(n == 0 && k == 0)    return dp[n][k] = 1;
    if(n == 0 || k == 0)    return dp[n][k] = 0;
    return dp[n][k] = ((k*gen(n-1,k))+gen(n-1,k-1))%MOD;
}
int main(){
    int q,n,k;
    cin >> q;
    memset(dp,-1,sizeof dp);
    while(q--){
        cin >> n  >> k;
        cout << gen(n,k) << endl;
    }
    return 0;
}
