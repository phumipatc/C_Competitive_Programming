/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long a[110];
int main(){
    long long n,m,l = 0,r = 1e9,mid,countt,sum;
    scanf("%lld %lld",&n,&m);
    for(long long i=1;i<=m;i++){
        scanf("%lld",&a[i]);
        l = max(l,a[i]);
    }
    while(l<r){
        mid = (l+r)/2,sum = 0,countt = 1;
        for(long long i=1;i<=m;i++){
            sum+=a[i];
            if(sum>mid){
                sum = a[i];
                countt++;
            }
        }
        if(countt<=n)   r = mid;
        else            l = mid+1;
    }
    printf("%lld\n",l);
	return 0;
}
