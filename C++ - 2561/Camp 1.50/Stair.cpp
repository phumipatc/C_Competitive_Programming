/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int dp[5010];
int main(){
    int n,k;
    cin >> n >> k;
    dp[0] = 1;
    for(int i=1;i<=n;i++)
        for(int j=n;j>=i;j--)
            dp[j] = (dp[j]+dp[j-i])%k;
    cout << dp[n]-1;
	return 0;
}
