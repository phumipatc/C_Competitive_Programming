/*
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
char a[1000010];
LL dp[1000010][3];
int main(){
    ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
    int q,n;
    cin >> q;
    while(q--){
        cin >> a+1;
        n = strlen(a+1);
        for(int i=1;i<=n;i++){
            if(a[i] == 'A')         dp[i][0]++;
            else if(a[i] == 'B')    dp[i][1]+=dp[i-1][0];
            else                    dp[i][2]+=dp[i-1][1];
            dp[i][0]+=dp[i-1][0];
            dp[i][1]+=dp[i-1][1];
            dp[i][2]+=dp[i-1][2];
        }
        cout << dp[n][2] << "\n";
        memset(dp,0,sizeof dp);
    }
    return 0;
}