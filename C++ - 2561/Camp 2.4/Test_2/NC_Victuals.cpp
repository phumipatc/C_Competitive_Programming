/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
#define MOD 99877
using namespace std;
map<long long ,long long > mapp;
long long qs[100010];
int main(){
    long long n,t,q,a,b,c,i,j;
    scanf("%lld %lld %lld",&n,&t,&q);
    for(i=1;i<=n;i++){
        scanf("%lld",&j);
        mapp[j] = i;
    }
    while(t--){
        scanf("%lld %lld %lld",&a,&b,&c);
        qs[mapp[a]]+=c;
        qs[mapp[b]+1]-=c;
    }
    for(i=1;i<=n;i++)
        qs[i]=(((qs[i]+qs[i-1])%MOD)+MOD)%MOD;
    for(i=1;i<=n;i++)
        qs[i]=(((qs[i]+qs[i-1])%MOD)+MOD)%MOD;
    while(q--){
        scanf("%lld %lld",&a,&b);
        printf("%lld\n",(((qs[mapp[b]]-qs[mapp[a]-1])%MOD)+MOD)%MOD);
    }
    return 0;
}
