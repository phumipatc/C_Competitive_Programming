/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int a[10010];
unordered_map<long long ,long long > mapp[10010];
long long choose(int n,int k){
    if(n == 0)          return 1;
    if(k ==0 || k == n) return 1;
    if(mapp[n][k])      return mapp[n][k];
    return mapp[n][k] = (choose(n-1,k-1)+choose(n-1,k))%MOD;
}
int main(){
    int n,k;
    scanf("%lld %lld",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    long long ans = 0;
    for(long long i=n;i>=k;i--)
        ans = (ans+(a[i]*choose(i-1,k-1))%MOD)%MOD;
    printf("%lld\n",ans);
	return 0;
}