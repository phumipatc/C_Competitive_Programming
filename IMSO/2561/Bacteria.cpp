/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[32][32],countt[910],cnt[910],dp[32][32][32][32];
int divide(int x1,int y1,int x2,int y2){
	if(x1>=x2 || y1>=y2)		return 0;
	if(dp[x1][y1][x2][y2]!=-1)	return dp[x1][y1][x2][y2];
	int ans = 0;
	for(int i=x1;i<x2;i++){
		for(int j=x1;j<=i;j++){
			for(int k=y1;k<=y2;k++){
				cnt[a[j][k]]++;
			}
		}
		for(int i=1;i<=m;i++){
			if(cnt[i]!=0){
				
			}
		}
	}
	for(int i=y1;i<y2;i++){

	}
}
int main(){
	freopen("0_in.txt","r",stdin);
	freopen("0_out.txt","w",stdout);
	int l,w,m;
	scanf("%d %d %d",&l,&w,&m);
	for(int i=1;i<=l;i++){
		for(int j=1;j<=w;j++){
			scanf("%d",&a[i][j]);
			countt[a[i][j]]++;
		}
	}
	memset(dp,-1,sizeof dp);
	printf("%d\n",divide(1,1,l,w));
	return 0;
}
