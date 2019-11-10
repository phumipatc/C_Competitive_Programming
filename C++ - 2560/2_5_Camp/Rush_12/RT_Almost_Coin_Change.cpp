/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long coin[25],dp[2000005];
int main(){
    long long n,m,k;
    scanf("%lld %lld %lld",&n,&m,&k);
    for(long long i=1;i<=n;i++)
        scanf("%lld",&coin[i]);
    for(long long i=1;i<=2000000;i++)
        dp[i] = 1e18;
    for(long long i=1;i<=n;i++)
        for(long long j=coin[i];j<=2000000;j++)
            if(dp[j-coin[i]]!=1e18)
                dp[j] = min(dp[j],dp[j-coin[i]]+1);
    long long minn = 1e18,now;
    for(long long i=m;i<=m+k;i++){
        if(minn>dp[i]){
            minn = dp[i];
            now = i;
        }
    }
    if(minn == 1e18)    printf("-1\n");
    else                printf("%lld\n%lld\n",minn,now-m);
    return 0;
}
