/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long a[200010],b[200010],dp[200010];
int main(){
    long long q,n,c;
    scanf("%lld",&q);
    while(q--){
        scanf("%lld %lld",&n,&c);
        for(long long i=0;i<n;i++){
            scanf("%lld",&a[i]);
            a[i+n] = a[i];
        }
        for(long long i=0;i<n;i++){
            scanf("%lld",&b[i]);
            b[i+n] = b[i];
        }
        long long force = 0,st = 0,ch = 0;
        for(long long i=0;i<2*n;i++){
            force = min(c,force+a[i])-b[i];
            if(force<0)	st = i+1,force = 0;
            if(i-st+1 == n){
                ch = 1;
                break;
            }
        }
        if(!ch){
            printf("0\n");
            continue;
        }
		long long ans = 1;
		for(long long i=(st-1+n)%n;i!=st;i=(i-1+n)%n){
			long long temp = max(0ll,b[i]-min(c,a[i]));
			dp[i] = max(temp,dp[(i+1)%n]-(min(c,a[i])-b[i]));
			if(min(a[i],c)-b[i]>=dp[(i+1)%n])	ans++;
		}
		printf("%lld\n",ans);
		memset(dp,0,sizeof dp);
    }
	return 0;
}
