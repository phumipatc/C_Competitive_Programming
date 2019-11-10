/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long n,p,dp[10000010];
int main(){
    scanf("%lld %lld",&n,&p);
    dp[n] = 1;
    for(int i=n-1;i>=2;i--){
        dp[i] = dp[i+1];
        if(i*2<=n)  dp[i]+=dp[i*2];
        dp[i]%=p;
    }
    printf("%lld\n",dp[2]);
	return 0;
}
