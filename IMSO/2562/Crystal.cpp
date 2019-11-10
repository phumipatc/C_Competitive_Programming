/*
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
#define MOD 10001
using namespace std;
typedef long long LL;
int dp[1010];
int main(){
    ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
    int n;
    dp[0] = 1;
    for(int i=1;i<=1000;i++){
        for(int j=0;j<i;j++){
            dp[i]+=dp[j]*dp[i-j-1];
            dp[i]%=MOD;
        }
    }
    cin >> n;
    cout << dp[n];
    return 0;
}