/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long a[100100];
int main(){
    long long n,p,l,r,mid,sum;
    scanf("%lld %lld",&n,&p);
    for(long long i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    l = 1,r = 2000000000;
    while(l<r){
        mid = (l+r)/2,sum = n;
        for(long long i=1;i<=n;i++)
            sum+=mid/a[i];
        if(sum>=p)  r = mid;
        else        l = mid+1;
    }
    printf("%lld\n",l);
    return 0;
}
