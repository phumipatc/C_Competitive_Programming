/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long key[100005],use[100005];
int main(){
    long long n,k,num,loop=0,ans=0;
    scanf("%lld %lld",&n,&k);
    for(long long i=1;i<=n;i++){
        scanf("%lld",&num);
        key[num]=i;
    }
    for(long long i=1;i<n;i++){
        use[i]=(key[i+1]-key[i]+n)%n;
        loop+=use[i];
    }
    use[n] = (key[1]-key[n]+n)%n;
    loop+=use[n];
    k--;
    ans = loop*(k/n);
    k%=n;
    for(long long i=1;i<=k;i++) ans+=use[i];
    printf("%lld\n",ans+key[1]-1);
    return 0;
}
