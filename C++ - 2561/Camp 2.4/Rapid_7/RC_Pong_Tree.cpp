/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
long long dp[355];
int main(){
    long long q,n;
    dp[0] = dp[1] = 1;
    for(long long i=2;i<=350;i++){
        for(long long j=0;j<=i-1;j++){
            for(long long k=0;k<=i-j-1;k++){
                dp[i]+=((dp[j]*dp[k])%MOD)*dp[i-j-k-1];
                dp[i]%=MOD;
            }
        }
    }
    scanf("%lld",&q);
    while(q--){
        scanf("%lld",&n);
        printf("%lld\n",dp[n]);
    }
	return 0;
}
