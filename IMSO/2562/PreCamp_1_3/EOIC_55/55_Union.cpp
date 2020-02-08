/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long y,x;
    bool operator<(const A&o) const{
        if(y!=o.y)  return y>o.y;
        else        return x<o.x;
    }
};
A a[1000020];
int main()
{
    long long n,u,v,i,maxx = 0,ans = 0;
    scanf("%lld",&n);
    for(i=1;i<=n;i++){
        scanf("%lld %lld",&u,&v);
        u/=2;
        v/=2;
        a[i].y = u;
        a[i].x = v;
    }
    sort(a+1,a+1+n);
    a[n+1].y = a[n+1].x = 0;
    for(i=1;i<=n;i++){
        if(a[i].y == a[i+1].y)  continue;
        if(a[i].x<maxx)         a[i].x = maxx;
        ans+=(a[i].y-a[i+1].y) * a[i].x;
        maxx = max(maxx,a[i].x);
    }
    printf("%lld\n",ans*4);
    return 0;
}
