/*
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MOD = 1000007;
int dp[50010];
int main(){
    ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
    int n,m,num;
    cin >> n >> m;
    dp[0] = 1;
    for(int i=1;i<=n;i++){
        cin >> num;
        for(int j=m;j>=num;j--){
            dp[j]+=dp[j-num];
            dp[j]%=MOD;
        }
    }
    cout << dp[m] << "\n";
    return 0;
}