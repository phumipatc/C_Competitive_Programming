/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long countt[100001],dp[100001];
int main(){
    long long q,ans,n,num,maxx;
    scanf("%lld",&q);
    while(q--){
        ans = maxx = 0;
        scanf("%lld",&n);
        for(long long i=1;i<=n;i++){
            scanf("%lld",&num);
            countt[num]++;
            maxx = max(maxx,num);
        }
        for(int i=maxx;i>=1;i--)
            dp[i] = max(dp[i+2]+(countt[i]*i),dp[i+1]);
        printf("%lld\n",dp[1]);
        memset(dp,0,sizeof dp);
        memset(countt,0,sizeof countt);
    }
    return 0;
}
