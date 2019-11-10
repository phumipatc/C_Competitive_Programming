/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long w,s;
};
A a[1010];
long long dp[1010];
int main(){
    long long q,n;
    scanf("%lld",&q);
    while(q--){
        scanf("%lld",&n);
        for(long long i=1;i<=n;i++){
            scanf("%lld %lld",&a[i].w,&a[i].s);
            dp[i] = 1e9;
        }
        dp[0] = 0;
        for(long long i=n;i>=1;i--){
            for(long long j=n;j>=1;j--){
                if(dp[j-1]<=a[i].s){
                    dp[j] = min(dp[j],dp[j-1]+a[i].w);
                }
            }
        }
        for(int i=n;i>=1;i--){
            if(dp[i] == 1e9)    continue;
            printf("%d\n",i);
            break;
        }
    }
	return 0;
}
