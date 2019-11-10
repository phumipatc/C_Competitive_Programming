/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long a[100001];
int main(){
    long long n;
    scanf("%lld",&n);
    for(long long i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    long long minn=1e18;
    for(long long i=1;i<n;i++)
        minn=min(minn,a[i+1]-a[i]);
    printf("%lld\n",minn);
    return 0;
}
