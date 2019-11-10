/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long dp[4100],have[4100];
int main(){
    long long q,n,m,temp,num;
    scanf("%lld",&q);
    while(q--){
        scanf("%lld %lld",&n,&m);
        for(long long i=0;i<n;i++){
            scanf("%lld",&temp);
            while(temp--){
                scanf("%lld",&num);
                have[1ll<<i]|=(1ll<<(num-1));
            }
        }
        for(long long i=1;i<(1<<n);i++){
            for(long long j=1;j<i;j++){
                if(i&j) continue;
                temp = have[i] & have[j];
                if(dp[i]+dp[j]+max(have[i]^temp,have[j]^temp)<=dp[i|j]) continue;
                dp[i|j] = dp[i]+dp[j]+max(have[i]^temp,have[j]^temp),have[i|j] = have[i]^have[j];
            }
        }
        printf("%lld\n",dp[(1<<n)-1]);
        memset(dp,0,sizeof dp);
        memset(have,0,sizeof have);
    }
	return 0;
}
