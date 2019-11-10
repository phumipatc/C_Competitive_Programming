/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int dp[2][2010][2010];
int sfree(int na,int nb){
    if(dp[0][na][nb]!=-1)   return dp[0][na][nb];
    if(na == 1 && nb == 0)  return 1;
    dp[0][na][nb] = 0;
    if(na>1 && na-1>nb) dp[0][na][nb]+=sfree(na-1,nb),dp[0][na][nb]%=MOD;
    if(nb>0)            dp[0][na][nb]+=sfree(na,nb-1),dp[0][na][nb]%=MOD;
    return dp[0][na][nb];
}
int sful(int na,int nb){
    if(dp[1][na][nb]!=-1)   return dp[1][na][nb];
    if(na == 0 && nb == 0)  return 1;
    if(na>nb)               return dp[1][na][nb] = sful(na-1,nb)%MOD;
    dp[1][na][nb] = 0;
    if(nb-1>=na)    dp[1][na][nb]+=sful(na,nb-1),dp[1][na][nb]%=MOD;
    if(na>0)        dp[1][na][nb]+=sful(na-1,nb),dp[1][na][nb]%=MOD;
    return dp[1][na][nb];
}
int main(){
    int q,a,b;
    memset(dp,-1,sizeof dp);
    scanf("%d",&q);
    while(q--){
        scanf("%d-%d",&a,&b);
        printf("%d %d\n",sfree(a,b),sful(a,b));
    }
	return 0;
}
