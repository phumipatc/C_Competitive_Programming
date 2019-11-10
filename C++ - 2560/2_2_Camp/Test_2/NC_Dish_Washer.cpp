/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long dis,a,b;
    bool operator < (const A&o) const{
        return dis>o.dis;
    }
};
A a[1000100];
int main(){
    long long l,k;
    scanf("%lld %lld",&l,&k);
    for(long long i=1;i<=k;i++){
        scanf("%lld %lld",&a[i].a,&a[i].b);
        a[i].dis=abs(a[i].b-a[i].a);
    }
    sort(a+1,a+k+1);
    long long countt=0,sum=0;
    for(long long i=1;i<=k;i++){
        if(countt<l){
            if(a[i].a>=a[i].b)
                sum+=a[i].b;
            else
                sum+=a[i].a,countt++;
        }else
            sum+=a[i].b;
    }
    printf("%lld\n",sum);
    return 0;
}
