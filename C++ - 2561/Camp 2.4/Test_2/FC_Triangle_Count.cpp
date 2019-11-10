/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
double g[300100];
int main(){
    long long n;
    double a,b,c;
    scanf("%lld",&n);
    for(long long i=1;i<=n;i++){
        scanf("%lf %lf %lf",&a,&b,&c);
        g[i] = (-a)/b;
    }
    sort(g+1,g+n+1);
    long long countt = 1,ans = (n*(n-1)*(n-2))/6;
    ans%=MOD;
    g[n+1] = 1e18;
    for(long long i=1;i<=n;i++){
        if(g[i]!=g[i+1]){
            ans-=((countt*(countt-1)*(countt-2))/6);
            ans-=(((countt*(countt-1))/2)*(n-countt));
            ans%=MOD;
            ans+=MOD;
            ans%=MOD;
            countt = 0;
        }
        countt++;
    }
    printf("%lld\n",ans);
    return 0;
}
