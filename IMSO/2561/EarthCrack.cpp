/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[510][510],dp[510][510];
int main(){
	freopen("0_in.txt","r",stdin);
	freopen("0_out.txt","w",stdout);
	int q,n,m,ans;
	scanf("%d",&q);
	while(q--){
		scanf("%d %d",&n,&m);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				scanf("%d",&a[i][j]);
		for(int j=1;j<=m;j++)
			dp[n][j] = a[n][j];
		for(int i=n-1;i>=1;i--){
			for(int j=1;j<=m;j++){
				dp[i][j] = a[i][j];
				if(j-1>=1 && j+1<=m)
					dp[i][j]+=min(dp[i+1][j-1],min(dp[i+1][j],dp[i+1][j+1]));
				else if(j-1>=1)
					dp[i][j]+=min(dp[i+1][j-1],dp[i+1][j]);
				else
					dp[i][j]+=min(dp[i+1][j],dp[i+1][j+1]);
			}
		}
		ans = 1e9;
		for(int j=1;j<=m;j++)
			ans = min(ans,dp[1][j]);
		printf("%d\n",ans);
		memset(dp,0,sizeof dp);
	}
	return 0;
}
