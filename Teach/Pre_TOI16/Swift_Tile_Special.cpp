/*
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Algo	: DP
	Status	: 
*/
#include<bits/stdc++.h>
#define MOD 9241
using namespace std;
typedef long long LL;
typedef pair<int ,int > PII;
typedef pair<long long ,long long > PLL;
int dp[110][110];
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	dp[0][0] = 1;
	for(int i=1;i<=100;i++){
		for(int j=0;j<=100;j++){
			dp[i][j]+=dp[i-1][j];
			if(i>=2){
				dp[i][j]+=dp[i-2][j],dp[i][j]%=MOD;
				if(j>0)	dp[i][j]+=dp[i-2][j-1],dp[i][j]%=MOD;
			}
			for(int k=i-3;j>=2 && k>=0;k-=2)
				dp[i][j]+=dp[k][j-2]*2,dp[i][j]%=MOD;
			for(int k=i-4;j>=2 && k>=0;k-=2)
				dp[i][j]+=dp[k][j-2]*2,dp[i][j]%=MOD;
			// printf("%d %d %d\n",i,j,dp[i][j]);
		}
	}
	for(int i=1;i<=100;i++)
		for(int j=1;j<=100;j++)
			dp[i][j]+=dp[i][j-1],dp[i][j]%=MOD;
	int q,n,k;
	cin >> q;
	while(q--){
		cin >> n >> k;
		cout << dp[n][k] << '\n';
	}
	return 0;
}