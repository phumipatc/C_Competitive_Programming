/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
#define MOD (long long )(1e9+7)
using namespace std;
long long pre[110],in[110],dp[110][110];
long long traverse(long long now,long long l,long long r){
    if(l>=r)            return 1;
    if(dp[l][r]!=-1)    return dp[l][r];
    printf("processing:%lld %lld %lld{\n",now,l,r);
    long long idx;
    for(long long i=l;i<=r;i++){
        if(pre[now]!=in[i]) continue;
        idx = i;
        break;
    }
    long long ll = traverse(now+1,l,idx-1);
    long long st = now+idx-l+1;
    long long rr = 2*traverse(st,idx+1,r);
    for(){
        rr = (rr+(traverse(,idx+1,)*traverse(,,r))%MOD)%MOD;
    }
    printf("}\n");
    return dp[l][r] = (ll*rr)%MOD;
}
int main(){
    long long n;
    scanf("%lld",&n);
    for(long long i=1;i<=n;i++)
        scanf("%lld",&pre[i]);
    for(long long i=1;i<=n;i++)
        scanf("%lld",&in[i]);
    memset(dp,-1,sizeof dp);
    printf("%lld\n",traverse(1,1,n));
	return 0;
}