/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
#define MOD 2553
using namespace std;
int dp[5010][5010];
int play(int n,int k){
	if(n == 0)		return 1;
	if(k == 0)		return dp[n-1][k];
	if(dp[n][k])	return dp[n][k];
    return dp[n][k] = (play(n-1,k)+play(n,k-1))%MOD;
}
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    printf("%d\n",((play(n,k)*play(n,k))%MOD)*play(n,k));
	return 0;
}
