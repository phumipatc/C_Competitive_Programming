/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long k,ca,cb;
long long a[100010];
long long snap(long long l,long long r){
    long long ll = lower_bound(a+1,a+k+1,l)-a;
    long long rr = upper_bound(a+1,a+k+1,r)-a;
    if(l == r){
        if(a[ll] == l)  return cb*(rr-ll);
        else            return ca;
    }
    long long mid = (l+r)/2;
    if(ll == rr)    return ca;
    else            return min(cb*(r-l+1)*(rr-ll),snap(l,mid)+snap(mid+1,r));
}
int main(){
    long long n;
    scanf("%lld %lld %lld %lld",&n,&k,&ca,&cb);
    for(long long i=1;i<=k;i++)
        scanf("%lld",&a[i]);
    sort(a+1,a+k+1);
    printf("%lld\n",snap(1,1<<n));
	return 0;
}