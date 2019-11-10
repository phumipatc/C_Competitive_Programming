/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long wood[100100];
long long GCD(long long a,long long b){
    if(a%b == 0)    return b;
    else            return GCD(b,a%b);
}
int main(){
    long long n,cut = 0;
    scanf("%lld",&n);
    for(long long i=1;i<=n;i++){
        scanf("%lld",&wood[i]);
        cut+=(wood[i]-1);
    }
    for(long long i=2;i<=n;i++)
        cut-=GCD(wood[i-1],wood[i])-1;
    printf("%lld\n",cut);
    return 0;
}
