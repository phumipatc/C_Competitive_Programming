/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    long long q,s,a,b,c,num,t;
    scanf("%lld",&q);
    while(q--){
        scanf("%lld %lld %lld %lld",&s,&a,&b,&c);
        num = s/c;
        t = num/a;
        printf("%lld\n",num+(t*b));
    }
    return 0;
}
