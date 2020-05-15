/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long a[100100];
int main()
{
    long long n,num,maxx = 0;
    scanf("%lld",&n);
    for(long long i=0;i<n;i++){
        scanf("%lld",&num);
        a[num]+=num;
        maxx = max(maxx,num);
    }
    for(long long i=2;i<=maxx;i++)
        a[i] = max(a[i-1],a[i]+a[i-2]);
    printf("%lld\n",a[maxx]);
    return 0;
}