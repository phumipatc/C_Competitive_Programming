/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long p[110],pos[110],countt[110];
long long findroot(long long n){
    if(p[n] == n)   return n;
    else            return p[n] = findroot(p[n]);
}
long long gcd(long long a,long long b){
    if(a%b == 0)    return b;
    else            return gcd(b,a%b);
}
int main(){
    long long n,m,i,a,b,ra,rb,ans = 1;
    scanf("%lld %lld",&n,&m);
    for(i=1;i<=n;i++)   p[i] = pos[i] = i;
    for(i=1;i<=m;i++){
        scanf("%lld %lld",&a,&b);
        swap(pos[a],pos[b]);
    }
    for(i=1;i<=n;i++){
        ra = findroot(i),rb = findroot(pos[i]);
        if(ra!=rb)  p[ra] = rb;
    }
    for(i=1;i<=n;i++)
        countt[findroot(i)]++;
    for(i=1;i<=n;i++)
        if(countt[i])
            ans = ((ans*countt[i])/gcd(ans,countt[i]));
    printf("%lld",ans);
    return 0;
}
