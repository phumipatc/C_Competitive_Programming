/*
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Algo	: 
	Status	: 
*/
#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long LL;
typedef pair<int ,int > PII;
typedef pair<long long ,long long > PLL;
LL dp[100010];
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int n;
	cin >> n;
	dp[2] = 1;
	for(int i=3;i<=n;i++)
		dp[i] = (((dp[i-1]+dp[i-2])%MOD)*(i-1))%MOD;
	cout << dp[n] << '\n';
	return 0;
}