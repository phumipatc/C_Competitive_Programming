/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long a[1000010];
int main(){
    long long n,m;
    scanf("%lld %lld",&n,&m);
    for(long long i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    long long l = 1,r = 1e18,mid,countt;
    while(l<r){
        mid = (l+r)/2,countt = 0;
        for(long long i=1;i<=n;i++){
            countt+=mid/a[i];
        }
        if(countt>=m)   r = mid;
        else            l = mid+1;
    }
    printf("%lld\n",l);
	return 0;
}
