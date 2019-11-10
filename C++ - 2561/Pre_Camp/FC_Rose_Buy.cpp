/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long a[1000010];
int main(){
    long long n,k,temp,ans = -1e18,minn = 1e18;
    scanf("%lld %lld",&n,&k);
    for(long long i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        a[i]+=a[i-1];
        if(i>=k){
            minn = min(minn,a[i-k]);
            ans = max(ans,a[i]-minn);
        }
    }
    printf("%lld\n",ans);
	return 0;
}
