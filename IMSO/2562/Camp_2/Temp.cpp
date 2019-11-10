/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
#define MOD 2557
using namespace std;
int dp[1010];
int main(){
	int n;
	cin >> n;
	dp[0] = 1;
	for(int i=1;i<=n;i++){
		dp[i]+=dp[i-1];
		if(i>=3)	dp[i]+=dp[i-3];
		if(i>=4)	dp[i]+=dp[i-4];
		dp[i]%=MOD;
	}
	cout << dp[n];
	return 0;
}