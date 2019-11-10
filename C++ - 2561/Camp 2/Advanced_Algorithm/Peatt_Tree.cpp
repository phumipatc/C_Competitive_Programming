/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
#define MOD 9973
using namespace std;
int dp[1010];
int catalan(int n){
    if(n == 0)  return dp[0] = 1;
    if(n == 1)  return dp[1] = 1;
    if(dp[n])   return dp[n];
    int sum = 0;
    for(int i=0;i<n;i++)    sum = (sum+(catalan(i)%MOD)*(catalan(n-i-1)%MOD))%MOD;
    return dp[n] = (sum)%MOD;
}
int main(){
    int q,n;
    q = catalan(1000);
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        printf("%d\n",dp[n-1]);
    }
	return 0;
}
