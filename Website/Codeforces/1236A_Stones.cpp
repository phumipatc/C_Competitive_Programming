/*
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int dp[110][110][110];
int choose(int a,int b,int c){
    if(dp[a][b][c]!=-1)             return dp[a][b][c];
    dp[a][b][c] = 0;
    if(a>=1 && b>=2)
        dp[a][b][c] = max(dp[a][b][c],choose(a-1,b-2,c)+3);
    if(b>=1 && c>=2)
        dp[a][b][c] = max(dp[a][b][c],choose(a,b-1,c-2)+3);
    // printf("%d %d %d %d\n",a,b,c,dp[a][b][c]);
    return dp[a][b][c];
}
int main(){
    ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
    int q,a,b,c;
    cin >> q;
    memset(dp,-1,sizeof dp);
    while(q--){
        cin >> a >> b >> c;
        cout << choose(a,b,c) << "\n";
    }
    return 0;
}