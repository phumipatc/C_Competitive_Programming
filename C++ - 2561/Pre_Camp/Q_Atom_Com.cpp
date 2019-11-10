/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long dp[25][2100000];
int main(){
    long long q,n,k,st = (1<<20)-1;
    dp[1][st-1] = dp[1][st] = dp[1][st+1] = 1;
    for(long long i=2;i<=20;i++){
        for(long long j=0;j<=2*st;j++){
            dp[i][j]+=dp[i-1][j];
            if(j-(1<<(i-1))>=0)     dp[i][j]+=dp[i-1][j-(1<<(i-1))];
            if(j+(1<<(i-1))<=2*st)  dp[i][j]+=dp[i-1][j+(1<<(i-1))];
        }
    }
    scanf("%lld",&q);
    while(q--){
        scanf("%lld %lld",&n,&k);
        if(abs(n)>=(1<<20)) printf("0\n");
        else                printf("%lld\n",dp[k][st+n]);
    }
	return 0;
}
