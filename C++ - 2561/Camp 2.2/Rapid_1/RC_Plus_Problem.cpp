/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int main(){
    long long q,n,temp,ans;
    scanf("%lld",&q);
    while(q--){
        scanf("%lld",&n);
        if(n%2 == 0)    ans = (((n/2)%MOD)*((n+1)%MOD))%MOD;
        else            ans = ((n%MOD)*(((n+1)/2)%MOD))%MOD;
        printf("%lld\n",ans);
    }
	return 0;
}
