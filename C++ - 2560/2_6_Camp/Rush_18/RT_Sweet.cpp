/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long a[100005],temp[100005];
int main(){
    long long n,m,l,r;
    scanf("%lld %lld",&n,&m);
    for(long long i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    l = 0,r = a[n];
    while(l<r){
        long long mid = (l+r)/2,countt = 0,countt2 = 0;
        for(long long i=1;i<=n;i++){
            if(a[i]>mid)
                countt+=a[i]-mid;
            else
                countt2+=mid-a[i];
        }
        if(countt>m || countt>countt2)  l = mid+1;
        else                            r = mid;
    }
    printf("%lld\n",l);
    return 0;
}
