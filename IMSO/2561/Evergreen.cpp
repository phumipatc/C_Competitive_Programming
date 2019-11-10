/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long a[1100];
int main(){
    long long n,k;
    scanf("%lld %lld",&n,&k);
    for(long long i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    long long l = 0,r  = 1e9,now;
    while(l<r){
        long long mid = (l+r)/2,sum = (mid+1)*(mid+1);
        for(long long i=1;i<n;i++){
            sum+=(mid+1)*(mid+1);
            if(a[i]+mid>=a[i+1]-mid){
                now = a[i]+mid-(a[i+1]-mid)+1;
                if(now%2 == 1)
                    sum-=(((now-1)/2)+1)*(((now-1)/2)+1);
                else
                    sum-=(((now-2)/2)+1)*((((now-2)/2)+1)+1);
            }
        }
        if(sum<k)   l = mid+1;
        else        r = mid;
    }
    printf("%lld\n",l);
    return 0;
}
