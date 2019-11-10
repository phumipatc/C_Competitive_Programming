/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long a[200010],countt[200010];
int main(){
    long long n,q,l,r;
    scanf("%lld %lld",&n,&q);
    for(long long i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    while(q--){
        scanf("%lld %lld",&l,&r);
        countt[l]++,countt[r+1]--;
    }
    for(long long i=1;i<=n;i++)
        countt[i]+=countt[i-1];
    sort(countt+1,countt+n+1);
    long long sum = 0;
    for(long long i=1;i<=n;i++)
        sum+=countt[i]*a[i];
    printf("%lld\n",sum);
	return 0;
}