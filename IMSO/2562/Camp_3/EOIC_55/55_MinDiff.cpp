/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long a[100010];
int main(){
    long long n,minn = 1e18;
    scanf("%lld",&n);
    for(long long i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    for(long long i=1;i<n;i++)
        minn = min(minn,abs(a[i+1]-a[i]));
    printf("%lld\n",minn);
	return 0;
}