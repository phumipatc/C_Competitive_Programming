/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long dp[2][50010],qs[50010];
int main(){
	long long n,k,m,i,j,maxx;
	scanf("%lld %lld %lld",&n,&k,&m);
	for(i=1;i<=n;i++){
		scanf("%lld",&qs[i]);
		qs[i]+=qs[i-1];
	}
	maxx = -1e18;
	for(i=m;i<=n;i++){
		maxx = max(maxx,qs[i-m]);
		if(i == m)  dp[1][i] = qs[i]-maxx;
		else        dp[1][i] = min(qs[i]-maxx,dp[1][i-1]);
	}
	for(i=2;i<=k;i++){
		maxx = -1e18;
		for(j=i*m+i-1;j<=n;j++){
			maxx=max(maxx,qs[j-m]-dp[(i-1)%2][j-m-1]);
			if(j == i*m+i-1)    dp[i%2][j] = qs[j]-maxx;
			else                dp[i%2][j] = min(qs[j]-maxx,dp[i%2][j-1]);
		}
	}
	printf("%lld",qs[n]-dp[k%2][n]);
	return 0;
}