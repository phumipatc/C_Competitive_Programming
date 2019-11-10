/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long rose[1000100],minn[1000100];
int main(){
    long long n,k;
    scanf("%lld %lld",&n,&k);
    for(long long i=1;i<=n;i++){
        scanf("%lld",&rose[i]);
        rose[i]+=rose[i-1];
    }
    for(long long i=1;i<=n;i++)
        minn[i]=min(minn[i-1],rose[i]);
    long long maxx=-1e16;
    for(long long i=k;i<=n;i++)
        maxx=max(maxx,rose[i]-minn[i-k]);
    printf("%lld\n",maxx);
    return 0;
}
