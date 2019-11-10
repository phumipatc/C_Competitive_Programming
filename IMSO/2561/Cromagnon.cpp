/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
#define MOD 2009
using namespace std;
int k,a[110],mul[21][21],dp[110][110][21];
void multiply(int l,int r,int target){
	if(dp[l][r][target]!=-1)	return ;
	if(l == r){
		if(a[l] == target)	dp[l][r][target] = 1;
		else				dp[l][r][target] = 0;
		return ;
	}
	for(int t = 0;t<k;t++){
		dp[l][r][t] = 0;
		for(int i=0;i<k;i++){
			for(int j=0;j<k;j++){
				if(mul[i][j]!=t)	continue;
				for(int k=l;k<r;k++){
					multiply(l,k,i);
					multiply(k+1,r,j);
					dp[l][r][t]+=dp[l][k][i]*dp[k+1][r][j];
				}
			}
		}
	}
	return ;
}
int main(){
	freopen("0_in.txt","r",stdin);
	freopen("0_out.txt","w",stdout);
	int n;
	scanf("%d",&k);
	for(int i=0;i<k;i++)
		for(int j=0;j<k;j++)
			scanf("%d",&mul[i][j]);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	memset(dp,-1,sizeof dp);
	multiply(1,n,0);
	for(int i=0;i<k;i++)
		printf("%d\n",dp[1][n][i]);
	return 0;
}
