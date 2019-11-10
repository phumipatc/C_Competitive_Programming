/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int dp[300];
int main(){
    int n,k,w,m,r;
    cin >> n >> k;
    for(int i=1;i<=(1<<k);i++)
        dp[i] = 1e9;
    while(n--){
        cin >> w;
        m = 0;
        for(int i=0;i<k;i++){
            cin >> r;
            m = (m<<1)+r;
        }
        for(int i=0;i<=(1<<k);i++)
            dp[i|m] = min(dp[i|m],dp[i]+w);
    }
    cout << dp[(1<<k)-1];
	return 0;
}
