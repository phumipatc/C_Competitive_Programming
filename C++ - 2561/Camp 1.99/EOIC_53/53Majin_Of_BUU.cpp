/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
long long a[100010],qs[100010];
int main(){
    long long q,n,ans;
    scanf("%lld",&q);
    while(q--){
        ans = 0;
        scanf("%lld",&n);
        for(long long i=1;i<=n;i++)
            scanf("%lld",&a[i]);
        for(long long i=n;i>=1;i--) qs[i] = (a[i]+qs[i+1])%MOD;
        for(long long i=n;i>=1;i--) qs[i] = (qs[i]+qs[i+1])%MOD;
        for(long long i=1;i<n;i++)
            ans = (ans+(a[i]*qs[i+1]))%MOD;
        printf("%lld\n",ans);
        memset(qs,0,sizeof qs);
    }
	return 0;
}
