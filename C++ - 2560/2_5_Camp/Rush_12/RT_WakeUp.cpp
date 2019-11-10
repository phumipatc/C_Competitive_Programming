/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long x,y;
};
A a[15005];
long long dis[15005];
int main(){
    long long n,p,st,wake,minn,now,x,y,tx,ty;
    scanf("%lld %lld %lld %lld",&n,&p,&st,&wake);
    for(long long i=1;i<=n;i++)
        scanf("%lld %lld",&a[i].x,&a[i].y);
    swap(a[st],a[1]);
    for(long long i=1;i<=n;i++)
        dis[i] = 1e18;
    for(long long i=1;i<n;i++){
        minn = 1e18;
        for(long long j=i+1;j<=n;j++){
            x = tx = abs(a[i].x-a[j].x);
            y = ty = abs(a[i].y-a[j].y);
            for(long long i=2;i<=p;i++)
                x*=tx,y*=ty;
            dis[j] = min(dis[j],(long long)(x+y));
            if(minn>dis[j]){
                minn = dis[j];
                now = j;
            }
        }
        swap(dis[now],dis[i+1]);
        swap(a[now],a[i+1]);
    }
    long long ans = 0;
    for(long long i=2;i<=n;i++)
        ans+=dis[i];
    ans*=2;
    ans+=wake*(n-1);
    printf("%lld\n",ans);
    return 0;
}
