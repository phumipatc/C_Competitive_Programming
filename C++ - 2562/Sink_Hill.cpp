/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int a[1010][1010],dp[1010][1010][4];
//0 up	1 down	2 left	3 right
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int q,r,c;
	cin >> q;
	while(q--){
		cin >> r >> c;
		for(int i=1;i<=r;i++)
			for(int j=1;j<=c;j++)
				cin >> a[i][j];
		for(int i=1;i<=r;i++){
			for(int j=1;j<=c;j++){
				dp[i][j][0] = ((a[i][j]>=a[i-1][j])?dp[i-1][j][0]:0)+1;
				dp[i][j][2] = ((a[i][j]>=a[i][j-1])?dp[i][j-1][2]:0)+1;
			}
			for(int j=c;j>=1;j--)
				dp[i][j][3] = ((a[i][j]>=a[i][j+1])?dp[i][j+1][3]:0)+1;
		}
		for(int i=r;i>=1;i--)
			for(int j=1;j<=c;j++)
				dp[i][j][1] = ((a[i][j]>=a[i+1][j])?dp[i+1][j][1]:0)+1;
		int ans = 0;
		pair<int ,int > pos;
		for(int i=1;i<=r;i++){
			for(int j=1;j<=c;j++){
				int sum = 0;
				for(int k=0;k<4;k++)
					sum+=dp[i][j][k];
				sum-=3;
				if(ans<sum){
					ans = sum;
					pos = {i,j};
				}
			}
		}
		cout << ans << '\n' << pos.first << ' ' << pos.second << '\n';
		memset(a,0,sizeof a);
		memset(dp,0,sizeof dp);
	}
	return 0;
}