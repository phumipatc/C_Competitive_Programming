/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n,s,temp,m;
    scanf("%lld %lld",&n,&s);
    m = 0,temp = n;
    while(temp>0)
        m+=temp%10,temp/=10;
    if(n-m<s){
        printf("0\n-1\n");
        return 0;
    }
    long long l = 0,r = n;
    while(l<r){
        long long mid = (l+r)/2;
        m = 0,temp = mid;
        while(temp>0){
            m+=temp%10;
            temp/=10;
        }
        if(mid-m>=s)    r = mid;
        else            l = mid+1;
    }
    printf("%lld\n%lld\n",n-l+1,n);
    return 0;
}
