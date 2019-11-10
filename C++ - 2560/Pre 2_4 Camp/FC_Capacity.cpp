/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
#define MOD 49999
using namespace std;
long long a[11000];
int main(){
    long long n,sum=0,ans=0,ans2=1;
    scanf("%lld",&n);
    for(long long i=0;i<n;i++)
        scanf("%lld",&a[i]);
    sort(a,a+n);
    for(long long i=0;i<n;i++){
        ans+=(a[i]*i)-sum;
        ans%=MOD;
        sum+=a[i];
    }
    for(long long i=1;i<=n-2;i++){
        ans2*=i;
        ans2%=MOD;
    }
    printf("%lld\n",(ans*ans2)%MOD);
    return 0;
}
