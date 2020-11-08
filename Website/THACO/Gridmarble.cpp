/*
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Langauge: C++
	Algo	: Dynamic Programming
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int ,int > PII;
typedef pair<long long ,long long > PLL;
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int n,m;
	char c;
	cin >> n >> m;
	int a[n+5][m+5];
	pair<int ,int > dp[n+5][m+5];
	memset(a,0,sizeof a);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin >> c;
			if(c == 'R')	a[i][j] = 1;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(i == 1 && j == 1)	dp[i][j] = {0,0};
			else					dp[i][j] = {min(dp[i-1][j].first,dp[i][j-1].first),
												max(dp[i-1][j].second,dp[i][j-1].second)};
			dp[i][j].first+=a[i][j],dp[i][j].second+=a[i][j];
		}
	}
	return 0;
}