/*
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL mod_of_pow(LL a,LL n,LL m){
    if(n == 0)  return 1;
    LL ret = mod_of_pow(a,n/2,m);
    // printf("%lld %lld %lld\n",a,n,ret);
    if(n%2)     return (((ret*ret)%m)*a)%m;
    else        return (ret*ret)%m;
}
int main(){
    // ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
    LL q,a,b,c;
    scanf("%lld",&q);
    while(q--){
        scanf("%lld %lld %lld",&a,&b,&c);
        for(LL i=1;i<=log2(1000000);i++){
            if(mod_of_pow(a,c,1<<i) == mod_of_pow(b,c,1<<i))    continue;
            printf("%lld\n",i-1);
            break;
        }
    }
    return 0;
}