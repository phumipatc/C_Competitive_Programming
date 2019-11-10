/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long a[1000001],dp[1000001],ans[1000001];
int main(){
    long long n,q,st,en;
    scanf("%lld",&n);
    for(long long i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        dp[i]=a[i]-a[i-1];
        if(dp[i]<0) dp[i]=0;
        if(i==1)    continue;
        ans[i]=dp[i]+ans[i-1];
    }
    scanf("%lld",&q);
    while(q--){
        scanf("%lld %lld",&st,&en);
        printf("%lld\n",ans[en]-ans[st]);
    }
    return 0;
}

