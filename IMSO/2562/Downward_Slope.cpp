/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
#define MOD (long long )(1e9-1)
using namespace std;
long long a[80010],tree[42][80010];
long long dp[80010][42];
void update(long long lv,long long idx,long long v){
    while(idx<=80003){
        tree[lv][idx]+=v;
        tree[lv][idx]%=MOD;
        idx+= idx & -idx;
    }
}
long long query(long long lv,long long idx){
    long long sum = 0;
    while(idx>0){
        sum+=tree[lv][idx];
        sum%=MOD;
        idx-= idx & -idx;
    }
    return sum%MOD;
}
int main(){
    long long n,k;
    scanf("%lld %lld",&n,&k);
    for(long long i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    dp[0][0] = 1;
    update(0,n+1,1);
    for(long long i=1;i<=n;i++){
        for(long long j=1;j<=k;j++){
            dp[i][j] = (query(j-1,n+1)-query(j-1,a[i])+MOD)%MOD;
            update(j,a[i],dp[i][j]);
            // printf("%lld %lld %lld\n",i,j,dp[i][j]);
        }
    }
    printf("%lld\n",query(k,n));
	return 0;
}