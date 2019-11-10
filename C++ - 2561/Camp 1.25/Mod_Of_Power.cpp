/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long c;
long long modofpower(long long a,long long b){
    if(b == 1)  return a%c;
    long long temp = modofpower(a,b/2)%c;
    if(b%2 == 0)    return (temp*temp)%c;
    else            return (temp*temp*a)%c;
}
int main(){
    long long q,a,b;
    scanf("%lld",&q);
    while(q--){
        scanf("%lld %lld %lld",&a,&b,&c);
        printf("%lld\n",modofpower(a,b));
    }
	return 0;
}
