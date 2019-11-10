/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int dp[100010][4][4][4][4],a[100010];
int check(int i,int j,int k){
	int bit = 0;
	if(i)	bit|=(1<<i);
	if(j)	bit|=(1<<j);
	if(k)	bit|=(1<<k);
	return __builtin_popcount(bit);
}
int main(){
    int n;
    char temp;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf(" %c",&temp);
        if(temp == 'W')			a[i] = 1;
        else if(temp == 'D')	a[i] = 2;
		else if(temp == 'F')	a[i] = 3;
    }
	for(int i=1;i<=n;i++)
		for(int j=0;j<=3;j++)
			for(int k=0;k<=3;k++)
				for(int l=0;l<=3;l++)
					for(int m=0;m<=3;m++)
						dp[i][j][k][l][m] = -1e9;
	dp[1][0][a[1]][0][0] = dp[1][0][0][0][a[1]] = 1;
	for(int i=2;i<=n;i++){
		for(int j=0;j<=3;j++){
			for(int k=0;k<=3;k++){
				for(int l=0;l<=3;l++){
					for(int m=0;m<=3;m++){
						dp[i][k][a[i]][l][m] = max(dp[i][k][a[i]][l][m],dp[i-1][j][k][l][m]+check(j,k,a[i]));
						if(check(l,m,a[i]) == 1)
							dp[i][j][k][m][a[i]] = max(dp[i][j][k][m][a[i]],dp[i-1][j][k][l][m]+1);
						else if(check(l,m,a[i]) == 3)
							dp[i][j][k][m][a[i]] = max(dp[i][j][k][m][a[i]],dp[i-1][j][k][l][m]+3);
						else if(check(l,m,a[i]) == 2){
							if(l == 3 || m == 3 || a[i] == 3)
								dp[i][j][k][m][a[i]] = max(dp[i][j][k][m][a[i]],dp[i-1][j][k][l][m]+2);
							else
								dp[i][j][k][m][a[i]] = max(dp[i][j][k][m][a[i]],dp[i-1][j][k][l][m]+1);
						}
					}
				}
			}
		}
	}
	int ans = 0;
	for(int i=0;i<=3;i++)
		for(int j=0;j<=3;j++)
			for(int k=0;k<=3;k++)
				for(int l=0;l<=3;l++)
					ans = max(ans,dp[n][i][j][k][l]);
	printf("%d\n",ans);
	return 0;
}
