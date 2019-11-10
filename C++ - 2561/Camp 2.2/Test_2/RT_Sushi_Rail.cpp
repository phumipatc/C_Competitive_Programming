/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
long long a[100010],tree[400010],dp[100010][20];
void build(long long l,long long r,long long now){
    if(l == r){
        tree[now] = a[l];
        return ;
    }
    long long mid = (l+r)/2;
    build(l,mid,now*2);
    build (mid+1,r,(now*2)+1);
    tree[now] = (tree[now*2]*tree[(now*2)+1])%MOD;
}
long long query(long long l,long long r,long long now,long long ll,long long rr){
    if(r<ll || l>rr)    return 1;
    if(l>=ll && r<=rr)  return tree[now];
    long long mid = (l+r)/2;
    return (query(l,mid,now*2,ll,rr)*query(mid+1,r,(now*2)+1,ll,rr))%MOD;
}
int main(){
    long long n;
    scanf("%lld",&n);
    for(long long i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    build(1,n,1);
    memset(dp,-1,sizeof dp);
    for(long long i=1;i<=n;i++){
        dp[i][0] = max(dp[i-1][0],a[i]);
        for(long long j=1;j<17;j++){
            if(i<(1ll<<(j+1))-1)    continue;
            dp[i][j] = max(dp[i-1][j],dp[i-(1<<j)][j-1]+(query(1,n,1,i-(1<<j)+1,i))%MOD);
        }
    }
    long long ans = 0;
    for(int i=0;i<17;i++)
        ans = max(ans,dp[n][i]);
    printf("%lld\n",ans);
	return 0;
}
