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
    if(dp[n])   return dp[n];
    if(n == 0)  return 1;
    for(int i=0;i<n;i++){
        dp[n] = (dp[n]+(catalan(i)*catalan(n-i-1)))%MOD;
    }
    return dp[n];
}
int main(){
    int q,n;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        printf("%d\n",catalan(n-1));
    }
	return 0;
}
