/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long pos,val;
    bool operator < (const A&o) const{
        if(pos!=o.pos)  return pos<o.pos;
        else            return val<o.val;
    }
};
A a[200005];
int main(){
    long long n,en,sum = 0,ans = 0;
    scanf("%lld",&n);
    for(long long i=1;i<=2*n;i+=2){
        scanf("%lld %lld",&a[i].pos,&a[i+1].pos);
        a[i+1].pos++;
        a[i].val = 1;
        a[i+1].val = -1;
    }
    sort(a+1,a+(2*n)+1);
    for(long long i=1;i<(2*n);i++){
        sum+=a[i].val;
        ans+=max(0ll,sum-1)*(a[i+1].pos-a[i].pos);
    }
    printf("%lld\n",ans);
    return 0;
}
