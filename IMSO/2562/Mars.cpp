/*
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
char a[1010];
int dp[1010][30][30];
int dist(int a,int b){
    if(a>b) swap(a,b);
    return min(b-a,a+26-b);
}
int main(){
    ios_base::sync_with_stdio(0);	cin.tie(0);
    int q,n;
    cin >> q;
    while(q--){
        cin >> a+1;
        n = strlen(a+1);
        for(int i=0;i<=n;i++)
            for(int j=0;j<26;j++)
                for(int k=0;k<26;k++)
                    dp[i][j][k] = 1e9;
        dp[0][0][0] = 0;
        for(int i=1;i<=n;i++){
            for(int j=0;j<26;j++){
                for(int k=0;k<26;k++){
                    dp[i][a[i]-'A'][k] = min(dp[i][a[i]-'A'][k],dp[i-1][j][k]+dist(a[i]-'A',j));
                    dp[i][j][a[i]-'A'] = min(dp[i][j][a[i]-'A'],dp[i-1][j][k]+dist(a[i]-'A',k));
                }
            }
        }
        int ans = 1e9;
        for(int j=0;j<26;j++)
            for(int k=0;k<26;k++)
                ans = min(ans,dp[n][j][k]);
        cout << ans << "\n";
    }
    return 0;
}