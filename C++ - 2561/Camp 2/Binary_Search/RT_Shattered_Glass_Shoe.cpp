/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long a[100010],b[100010];
int main(){
    long long n,k,countt,l,r,mid;
    scanf("%lld",&n);
    for(long long i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    for(long long i=1;i<=n;i++)
        scanf("%lld",&b[i]);
    scanf("%lld",&k);
    l = 0,r = 2000000;
    while(l<r){
        mid = (l+r+1)/2,countt = 0;
        for(long long i=1;i<=n;i++)
            countt+=max(0ll,(mid*a[i])-b[i]);
        if(countt<=k)   l = mid;
        else            r = mid-1;
    }
    printf("%lld\n",l);
	return 0;
}
