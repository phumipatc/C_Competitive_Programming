/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
char a[260];
int dp[260][260][3],res[3][3] = {{2,1,0},{2,1,1},{1,2,1}};
int divide(int l,int r,int k){
	if(dp[l][r][0]!=-1)	return dp[l][r][k];
	for(int i=0;i<3;i++)
		dp[l][r][i] = 0;
	if(l == r){
		dp[l][r][a[l]-'0'] = 1;
		return dp[l][r][k];
	}
	for(int i=l;i<r;i++){
		for(int x=0;x<3;x++){
			for(int y=0;y<3;y++){
				if(dp[l][r][res[x][y]])	continue;
				if(!divide(l,i,x))		continue;
				if(!divide(i+1,r,y))	continue;
				dp[l][r][res[x][y]] = 1;
			}
		}
	}
	return dp[l][r][k];
}
int main(){
	int q = 20,n;
	while(q--){
		scanf("%d %s",&n,a+1);
		memset(dp,-1,sizeof dp);
		printf(divide(1,n,0)?"yes\n":"no\n");
	}
	return 0;
}