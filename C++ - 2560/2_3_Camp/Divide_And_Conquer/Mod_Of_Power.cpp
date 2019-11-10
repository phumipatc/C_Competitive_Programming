/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long Mod_Pow(long long a,long long b,long long c){
    if(b==0)    return 1;
    if(b==1)    return a%c;
    long long divide=Mod_Pow(a,b/2,c);
    if(b%2==0)
        return (divide*divide)%c;
    else
        return (divide*divide*a)%c;
}
int main(){
    long long q,a,b,c;
    scanf("%lld",&q);
    while(q--){
        scanf("%lld %lld %lld",&a,&b,&c);
        printf("%lld\n",Mod_Pow(a,b,c));
    }
    return 0;
}
