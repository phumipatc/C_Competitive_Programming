/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[1010][1010],dp[1010][1010][3];
int main(){
	freopen("0_in.txt","r",stdin);
	freopen("0_out.txt","w",stdout);
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&a[i][j]);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			for(int k=0;k<=2;k++)
				dp[i][j][0] = max(dp[i][j][0],max(dp[i-1][j][k],dp[i][j-1][k]));
			for(int k=1;k<=2;k++){
				dp[i][j][k] = max(dp[i-1][j][k-1],dp[i][j-1][k-1])+a[i][j];
			}
		}
	}
	printf("%d\n",max(dp[n][m][0],max(dp[n][m][1],dp[n][m][2])));
	return 0;
}
