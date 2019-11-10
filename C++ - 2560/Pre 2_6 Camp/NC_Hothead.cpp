/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
#define INF 1e18
using namespace std;
int m,a[1005];
long long dp[1005][1005][51];
long long play(int n,int k,int last,int sum){
    //if(k<0)         return INF;
    if(dp[n][last][k]!=-1)    return dp[n][last][k];
    if(n == m+1)    return 0;
    long long MIN = play(n+1,k,last,sum+a[n]);
    if(k!=0)    MIN = min(MIN,play(n+1,k-1,n,0));
    return dp[n][last][k] = MIN+sum;
}
int main(){
    int k;
    scanf("%d %d",&m,&k);
    for(int i=1;i<=m;i++){
        scanf("%d",&a[i]);
    }
    memset(dp,-1,sizeof dp);
    printf("%lld\n",play(1,k,0,0));
    return 0;
}
