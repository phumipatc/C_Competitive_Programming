/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long a[1010],dp[1010][1010][55];
long long maxn;
long long hot(long long n,long long k,long long last,long long sum){
	if(dp[n][last][k]!=-1)	return dp[n][last][k];
	if(n == maxn+1)			return 0;
	long long minn = hot(n+1,k,last,sum+a[n]);
	if(k)	minn = min(minn,hot(n+1,k-1,n,0));
	return dp[n][last][k] = minn+sum;
}
int main(){
    long long maxk;
    scanf("%lld %lld",&maxn,&maxk);
    for(long long i=1;i<=maxn;i++)
        scanf("%lld",&a[i]);
	memset(dp,-1,sizeof dp);
    printf("%lld\n",hot(1,maxk,0,0));
	return 0;
}