/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long id,v;
    bool operator < (const A&o) const{
        if(id!=o.id)    return id<o.id;
        else            return v<o.v;
    }
};
A a[100100];
int main(){
    long long n,m,ans = 0;
    scanf("%lld %lld",&n,&m);
    for(long long i=1;i<=n;i++)
        scanf("%lld %lld",&a[i].id,&a[i].v);
    sort(a+1,a+n+1);
    for(long long i=2;i<=n;i++){
        if(a[i-1].v>a[i].v)
            ans+=a[i-1].v-a[i].v;
    }
    printf("%lld\n",ans+a[n].v);
	return 0;
}
