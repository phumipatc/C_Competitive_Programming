/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
long long a[1000100],dp[1000100],ans[1000100];
int main(){
    long long n,q,aa,bb,i;
    scanf("%lld",&n);
    for(i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        dp[i]=a[i]-a[i-1];
        if(dp[i]<0) dp[i]=0;
        if(i!=1){
            ans[i]=dp[i]+ans[i-1];
        }
    }
    scanf("%lld",&q);
    while(q--){
        scanf("%lld %lld",&aa,&bb);
        printf("%lld\n",ans[bb]-ans[aa]);
    }
	return 0;
}
