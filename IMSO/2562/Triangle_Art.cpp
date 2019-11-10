/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int dp[110][110];
int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	dp[1][2] = dp[2][1] = 1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if((i == 1 && j == 2) || (i == 2 && j == 1))	continue;
			dp[i][j] = dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
			dp[i][j]%=MOD;
			for(int l=i-1;l>=1 && i-l<=k;l--){
				dp[i][j]+=dp[l-1][j-1]+1;
				dp[i][j]%=MOD;
			}
			for(int l=j-1;l>=1 && j-l<=k;l--){
				dp[i][j]+=dp[i-1][l-1]+1;
				dp[i][j]%=MOD;
			}
		}
	}
	printf("%d\n",dp[n][n]);
	return 0;
}
