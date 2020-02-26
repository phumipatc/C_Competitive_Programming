/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long a[1010][1010];
int main(){
	freopen("10.in","r",stdin);
	freopen("10.sol","w",stdout);
    long long n,m,k;
    scanf("%lld %lld %lld",&n,&m,&k);
    for(long long i=1;i<=n;i++){
        for(long long j=1;j<=m;j++){
            scanf("%lld",&a[i][j]);
            a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
        }
    }
    long long ans = -1e18;
    for(long long i=k;i<=n;i++)
        for(long long j=k;j<=m;j++)
            ans = max(ans,a[i][j]-a[i-k][j]-a[i][j-k]+a[i-k][j-k]);
    printf("%lld\n",ans);
    return 0;
}
