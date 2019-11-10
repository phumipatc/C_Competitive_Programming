/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long a[2100];
long long ans;
int main(){
    long long n;
    scanf("%lld",&n);
    for(long long i=1;i<=2*n;i++)
        scanf("%lld",&a[i]);
    sort(a+1,a+(2*n)+1);
    for(long long i=1;i<=n;i++)
        ans+=(a[i]*a[(2*n)-i+1]);
    printf("%lld\n",ans);
    return 0;
}
