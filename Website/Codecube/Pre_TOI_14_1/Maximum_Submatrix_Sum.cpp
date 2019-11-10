/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long a[100010],b[100010];
int main(){
    long long n,x,y;
    scanf("%lld %lld %lld",&n,&x,&y);
    for(long long i=1;i<=n;i++)
        scanf("%lld",&a[i]),a[i]+=a[i-1];
    for(long long i=1;i<=n;i++)
        scanf("%lld",&b[i]),b[i]+=b[i-1];
    long long maxy=0,maxx=0;
    for(long long i=x;i<=n;i++)
        maxy=max(maxy,a[i]-a[i-x]);
    for(long long i=y;i<=n;i++)
        maxx=max(maxx,b[i]-b[i-y]);
    printf("%lld",(maxy*y)+(maxx*x));
}
