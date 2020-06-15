/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int a[1510][1510];
int dp[1510][1510][4];
int minr[1510],minc[1510],qsr[1510][1510],qsc[1510][1510];
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int r,c;
	cin >> r >> c;
	for(int i=1;i<=r;i++)
		for(int j=1;j<=c;j++)
			cin >> a[i][j];
	for(int i=1;i<=r;i++)
		for(int j=1;j<=c;j++)
			qsr[i][j] = a[i][j]+qsr[i][j-1],qsc[i][j] = a[i][j]+qsc[i-1][j],minr[i] = minc[j] = 1e9;
	//From upleft
	for(int i=1;i<=r;i++){
		for(int j=1;j<=c;j++){
			if(i == 1)		dp[i][j][0] = dp[i][j-1][0];
			else if(j == 1)	dp[i][j][0] = dp[i-1][j][0];
			else			dp[i][j][0] = min(dp[i-1][j][0],dp[i][j-1][0]);
			dp[i][j][0]+=a[i][j];
		}
	}
	//From downleft
	for(int i=r;i>=1;i--){
		for(int j=1;j<=c;j++){
			if(i == r)		dp[i][j][1] = dp[i][j-1][1];
			else if(j == 1)	dp[i][j][1] = dp[i+1][j][1];
			else			dp[i][j][1] = min(dp[i+1][j][1],dp[i][j-1][1]);
			dp[i][j][1]+=a[i][j];
		}
	}
	//From upright
	for(int i=1;i<=r;i++){
		for(int j=c;j>=1;j--){
			if(i == 1)		dp[i][j][2] = dp[i][j+1][2];
			else if(j == c)	dp[i][j][2] = dp[i-1][j][2];
			else			dp[i][j][2] = min(dp[i-1][j][2],dp[i][j+1][2]);
			dp[i][j][2]+=a[i][j];
		}
	}
	//From downright
	for(int i=r;i>=1;i--){
		for(int j=c;j>=1;j--){
			if(i == r)		dp[i][j][3] = dp[i][j+1][3];
			else if(j == c)	dp[i][j][3] = dp[i+1][j][3];
			else			dp[i][j][3] = min(dp[i+1][j][3],dp[i][j+1][3]);
			dp[i][j][3]+=a[i][j];
		}
	}
	int ans = 1e9;
	for(int i=1;i<=r;i++){
		for(int j=1;j<=c;j++){
			minc[j] = min(minc[j],dp[i][j][0]+dp[i][j][2]-qsc[i-1][j]-(2*a[i][j]));
			minr[i] = min(minr[i],dp[i][j][0]+dp[i][j][1]-qsr[i][j-1]-(2*a[i][j]));
			ans = min(ans,dp[i][j][1]+dp[i][j][3]+qsc[i][j]+minc[j]-(2*a[i][j]));
			ans = min(ans,dp[i][j][2]+dp[i][j][3]+qsr[i][j]+minr[i]-(2*a[i][j]));
		}
	}
	cout << ans << '\n';
	return 0;
}