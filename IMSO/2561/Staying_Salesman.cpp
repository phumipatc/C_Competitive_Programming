/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int dp[1010][8][3][1010],stay[3];
int main(){
	// freopen("0_in.txt","r",stdin);
	// freopen("0_out.txt","w",stdout);
	int n,a = 0,b = 1,c = 2;
	scanf("%d",&n);
	for(int i=0;i<3;i++)
		scanf("%d",&stay[i]);
	dp[1][(1<<a)][a][1] = 1;
	for(int i=2;i<=n;i++){
		for(int j=0;j<=7;j++){
			//a->b && a->c
			for(int k=1;k<=stay[a];k++){
				dp[i][j|(1<<b)][b][1]+=dp[i-1][j][a][k];
				dp[i][j|(1<<c)][c][1]+=dp[i-1][j][a][k];
				dp[i][j|(1<<b)][b][1]%=MOD;
				dp[i][j|(1<<c)][c][1]%=MOD;
			}
			//b->c
			for(int k=1;k<=stay[b];k++){
				dp[i][j|(1<<c)][c][1]+=dp[i-1][j][b][k];
				dp[i][j|(1<<c)][c][1]%=MOD;
			}
			//c->a
			for(int k=1;k<=stay[c];k++){
				dp[i][j|(1<<a)][a][1]+=dp[i-1][j][c][k];
				dp[i][j|(1<<a)][a][1]%=MOD;
			}
			for(int k=2;k<=stay[a];k++)
				dp[i][j][a][k] = dp[i-1][j][a][k-1];
			for(int k=2;k<=stay[b];k++)
				dp[i][j][b][k] = dp[i-1][j][b][k-1];
			for(int k=2;k<=stay[c];k++)
				dp[i][j][c][k] = dp[i-1][j][c][k-1];
		}
	}
	int ans = 0;
	for(int k=1;k<=stay[a];k++){
		ans+=dp[n][7][a][k];
		ans%=MOD;
	}
	for(int k=1;k<=stay[b];k++){
		ans+=dp[n][7][b][k];
		ans%=MOD;
	}
	for(int k=1;k<=stay[c];k++){
		ans+=dp[n][7][c][k];
		ans%=MOD;
	}
	printf("%d\n",ans);
	return 0;
}
