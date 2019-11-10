/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long dp[310][310],qs[310];
int main(){
    long long n,st,en,l,r;
    scanf("%lld",&n);
    for(long long i=1;i<=n;i++){
        scanf("%lld",&qs[i]);
        dp[i][i] = qs[i];
        qs[i]+=qs[i-1];
    }
    for(long long i=2;i<=n;i++){
        for(long long j=1;j<=n-i+1;j++){
            st=j,en=j+i-1;
            dp[st][en] = 1e18;
            for(long long k=st;k<=en;k++){
                l = 0,r = 0;
                if(k == st) l = 0;
                else        l = dp[st][k-1]+qs[k-1]-qs[st-1];
                if(k == en) r = 0;
                else        r = dp[k+1][en]+qs[en]-qs[k];
                dp[st][en]=min(dp[st][en],l+r+qs[k]-qs[k-1]);
            }
        }
    }
    printf("%lld\n",dp[1][n]);
    return 0;
}

