/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int a[1010][4],dp[1010][1010][10];
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int n,K;
	cin >> n >> K;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=3;j++)
			cin >> a[i][j];
	for(int i=0;i<=n;i++)
		for(int j=0;j<=K;j++)
			for(int k=0;k<8;k++)
				dp[i][j][k] = -1e9;
	for(int i=0;i<=n;i++)
			dp[i][0][0] = 0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=K;j++){
			// printf("%d %d:",i,j);
			for(int k=0;k<8;k++){
				dp[i][j][0] = max(dp[i][j][0],dp[i-1][j][k]);
				if((k&1) == 0 && dp[i-1][j-1][k]!=-1e9 && i!=1)
					dp[i][j][1] = max(dp[i][j][1],dp[i-1][j-1][k]+a[i][1]+a[i-1][1]);
				if((k&2) == 0 && dp[i-1][j-1][k]!=-1e9 && i!=1)
					dp[i][j][2] = max(dp[i][j][2],dp[i-1][j-1][k]+a[i][2]+a[i-1][2]);
				if((k&3) == 0 && j>=2 && dp[i-1][j-2][k]!=-1e9 && i!=1){
					dp[i][j][3] = max(dp[i][j][3],dp[i-1][j-2][k]+a[i][1]+a[i-1][1]+a[i][2]+a[i-1][2]);
					dp[i][j][7] = max(dp[i][j][7],dp[i-1][j-2][k]+a[i][1]+a[i][2]+a[i][3]+a[i-1][3]);
				}
				if(dp[i-1][j-1][k]!=-1e9)
					dp[i][j][3] = max(dp[i][j][3],dp[i-1][j-1][k]+a[i][1]+a[i][2]);
				if((k&4) == 0 && dp[i-1][j-1][k]!=-1e9 && i!=1)
					dp[i][j][4] = max(dp[i][j][4],dp[i-1][j-1][k]+a[i][3]+a[i-1][3]);
				if((k&5) == 0 && j>=2 && dp[i-1][j-2][k]!=-1e9 && i!=1)
					dp[i][j][5] = max(dp[i][j][5],dp[i-1][j-2][k]+a[i][1]+a[i-1][1]+a[i][3]+a[i-1][3]);
				if((k&6) == 0 && j>=2 && dp[i-1][j-2][k]!=-1e9 && i!=1){
					dp[i][j][6] = max(dp[i][j][6],dp[i-1][j-2][k]+a[i][2]+a[i-1][2]+a[i][3]+a[i-1][3]);
					dp[i][j][7] = max(dp[i][j][7],dp[i-1][j-2][k]+a[i][1]+a[i][2]+a[i][3]+a[i-1][1]);
				}
				if(dp[i-1][j-1][k]!=-1e9)
					dp[i][j][6] = max(dp[i][j][6],dp[i-1][j-1][k]+a[i][2]+a[i][3]);
			}
			if(j>=3 && dp[i-1][j-3][0]!=-1e9 && i!=1)
				dp[i][j][7] = max(dp[i][j][7],dp[i-1][j-3][0]+a[i][1]+a[i][2]+a[i][3]+a[i-1][1]+a[i-1][2]+a[i-1][3]);
			// for(int k=0;k<8;k++){
			// 	if(dp[i][j][k] == -1e9)	printf("-5 ");
			// 	else					printf("%d ",dp[i][j][k]);
			// }
			// printf("\n");
		}
	}
	int maxx = -1e9;
	for(int k=0;k<8;k++)
		maxx = max(maxx,dp[n][K][k]);
	cout << maxx << '\n';
	return 0;
}
/*
5 3
2 1 -1
1 3 2
0 2 3
2 1 1
3 3 0
*/