/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long a[100010];
int main(){
    long long n,m;
    scanf("%lld %lld",&n,&m);
    for(long long i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    long long mid,l = 1,r = 1e18,countt;
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
