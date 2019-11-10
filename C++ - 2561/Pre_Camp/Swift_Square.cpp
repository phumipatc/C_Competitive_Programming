/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int dp[12][10010],a[12];
int change(int n,int k){
    if(k<0)					return 1e9;
	if(dp[n][k]!=-1)		return dp[n][k];
	if(k == 0 && n>0)		return 1e9;
	if(n == 0 && k == 0)	return 0;
	if(n == 0)				return 1e9;
	int minn = 1e9;
	for(int i=1;i<=sqrt(k)+1;i++){
		minn = min(minn,change(n-1,k-(i*i))+((a[n]-i)*(a[n]-i)));
	}
	return dp[n][k] = minn;
}
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    memset(dp,-1,sizeof dp);
    if(change(n,k)!=1e9)    printf("%d\n",dp[n][k]);
    else                    printf("-1\n");
	return 0;
}
