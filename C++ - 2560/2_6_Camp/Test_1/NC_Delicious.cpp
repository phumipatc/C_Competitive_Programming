/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long a[100005],LIS[100005];
int main(){
    long long n,idx,maxx = 0;
    scanf("%lld",&n);
    for(long long i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        a[i]+=a[i-1];
        if(a[i]<0)  continue;
        idx = lower_bound(LIS,LIS+maxx,a[i])-LIS;
        if(idx == maxx) maxx++;
        LIS[idx] = a[i];
    }
    printf("%lld\n",idx+1);
    return 0;
}
