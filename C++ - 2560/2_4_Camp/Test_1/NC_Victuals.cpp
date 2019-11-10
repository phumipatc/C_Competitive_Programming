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
long long line[100001];
int main(){
    long long n,t,q,a,b,c,i,j;
    scanf("%lld %lld %lld",&n,&t,&q);
    for(i=1;i<=n;i++){
        scanf("%lld",&j);
        mapp[j] = i;
    }
    while(t--){
        scanf("%lld %lld %lld",&a,&b,&c);
        line[mapp[a]]+=c;
        line[mapp[b]+1]-=c;
    }
    for(i=1;i<=n;i++)
        line[i]=(((line[i]+line[i-1])%MOD)+MOD)%MOD;
    for(i=1;i<=n;i++)
        line[i]=(((line[i]+line[i-1])%MOD)+MOD)%MOD;
    while(q--){
        scanf("%lld %lld",&a,&b);
        printf("%lld\n",(((line[mapp[b]]-line[mapp[a]-1])%MOD)+MOD)%MOD);
    }
    return 0;
}
