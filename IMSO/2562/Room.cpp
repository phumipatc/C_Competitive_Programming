/*
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL MOD = 1000003; 
//1/a mod m = a^(mod-2)
LL mod_of_pow(int a,int n){
    if(n == 0)  return 1;
    LL ret = mod_of_pow(a,n/2);
    if(n%2)     return (((ret*ret)%MOD)*a)%MOD;
    else        return (ret*ret)%MOD;
}
int main(){
    ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
    LL n,k,ans = 1;
    cin >> n >> k;
    k = max(k,n-k);
    for(LL i=k+1;i<=n;i++)
        ans*=i,ans%=MOD;
    // cout << ans << "\n";
    LL temp = 1;
    for(LL i=2;i<=n-k;i++)
        temp*=i,temp%=MOD;
    ans*=mod_of_pow(temp,MOD-2),ans%=MOD;
    cout << ans << "\n";
    return 0;
}