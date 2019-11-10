/*
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
long long power(long long a,long long b)
{
    if(b == 0)  return 1;
    long long now = power(a,b/2);
    if(b%2) return (((now*now)%MOD)*a)%MOD;
    else    return now*now%MOD;
}
int main()
{
    long long n,m;
    scanf("%lld %lld",&n,&m);
    printf("%lld\n",power((power(2,m)-1+MOD)%MOD,n));
    return 0;
}