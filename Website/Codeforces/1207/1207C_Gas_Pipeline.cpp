/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
char a[200010];
long long dp[2][200010];
int main(){
    long long q,n,pip,pil;
    scanf("%lld",&q);
    while(q--){
        scanf("%lld %lld %lld %s",&n,&pip,&pil,a);
        dp[0][0] = pil;
        dp[1][0] = 1e18;
        a[n] = '0';
        for(long long i=1;i<=n;i++){
            if(a[i] == '1' || a[i-1] == '1'){
				dp[1][i] = min(dp[0][i-1]+pip,dp[1][i-1])+pip+2*pil;
				dp[0][i] = 1e18;
			}else{
				dp[1][i] = min(dp[0][i-1]+pip,dp[1][i-1])+pip+2*pil;
				dp[0][i] = min(dp[1][i-1]+pip,dp[0][i-1])+pip+pil;
			}
        }
        printf("%lld\n",dp[0][n]);
    }
	return 0;
}