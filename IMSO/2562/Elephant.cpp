/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int dp[100010];
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int n,num;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> num;
		if(i<=2)	continue;
		dp[i] = max(dp[i-1],num+dp[i-3]);
	}
	cout << dp[n] << '\n';
	return 0;
}