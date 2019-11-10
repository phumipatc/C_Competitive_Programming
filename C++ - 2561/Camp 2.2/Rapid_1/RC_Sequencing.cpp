/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
long long dp[500010];
long long powmod(long long n,long long k){
	if(n == 1)	return k%MOD;
	long long temp = powmod(n/2,k)%MOD;
	if(n%2)	return (((temp*temp)%MOD)*k)%MOD;
	else	return (temp*temp)%MOD;
}
long long sequencing(long long n,long long p,long long k){
	if(dp[k]!=-1)	return dp[k];
	// printf("%lld\n",k);
	long long sum = powmod(n,p/k);
	for(long long i=2;i<=p;i++){
		if(k*i>p)	break;
		sum = (sum+MOD-sequencing(n,p,k*i))%MOD;
	}
	return dp[k] = sum;
}
int main(){
    long long n,p,k;
    scanf("%lld %lld %lld",&n,&p,&k);
	memset(dp,-1,sizeof dp);
	printf("%lld\n",sequencing(n,p,k));
	return 0;
}
