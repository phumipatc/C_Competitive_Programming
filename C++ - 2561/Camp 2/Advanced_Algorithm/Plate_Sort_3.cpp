/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
#define MOD 9871
using namespace std;
int dp[1010][1010];
int stirling(int n,int k){
    if(dp[n][k])    return dp[n][k];
    if(n == k)      return dp[n][k] = 1;
    if(k == 1)      return dp[n][k] = 1;
    return dp[n][k] = (stirling(n-1,k-1)+(k*stirling(n-1,k)))%MOD;
}
int main(){
    int q,n,k;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&n,&k);
        printf("%d\n",stirling(n,k));
    }
	return 0;
}
