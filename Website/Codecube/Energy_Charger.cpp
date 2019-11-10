/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL a[1000010];
int main(){
    LL n,k,maxx = 0;
    scanf("%lld %lld",&n,&k);
    for(LL i=1;i<=n;i++)
        scanf("%lld",&a[i]),maxx = max(maxx,a[i]);
    LL l = maxx,r = 1e18;
    while(l<r){
        LL mid = (l+r)/2,countt = 0,sum = 0;
        for(int i=1;i<=n;i++){
            if(sum<a[i])    countt++,sum = mid;
            sum-=a[i];
        }
        if(countt>k)    l = mid+1;
        else            r = mid;
    }
    LL st = l;
    l = maxx,r = 1e18;
    while(l<r){
        LL mid = (l+r+1)/2,countt = 0,sum = 0;
        for(int i=1;i<=n;i++){
            if(sum<a[i])    countt++,sum = mid;
            sum-=a[i];
        }
        if(countt>=k)   l = mid;
        else            r = mid-1;
    }
    LL en = l;
    if(en == 1e18){
        printf("-1\n");
        return 0;
    }
    printf("%lld\n",en-st+1);
	return 0;
}
