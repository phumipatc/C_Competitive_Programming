/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long mod_of_pow(long long a,long long b,long long c){
    if(b == 1)      return a%c;
    long long temp = mod_of_pow(a,b/2,c)%c;
    if(b%2 == 0)    return (temp*temp)%c;
    else            return (temp*temp*a)%c;
}
int main(){
    long long q,n,m,c;
    scanf("%lld",&q);
    while(q--){
        scanf("%lld %lld %lld",&n,&m,&c);
        n = min(n,(long long)999999);
        n = (((1+n)*n)/2)%c;
        printf("%lld\n",mod_of_pow(n,m,c));
    }
	return 0;
}
