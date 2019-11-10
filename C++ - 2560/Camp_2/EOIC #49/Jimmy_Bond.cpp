/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
long long dp[30][1050000],work[30][30];
int n;
long long play(int mission,int bit){
    int i;
    long long mi=-1,tok;
    if(dp[mission][bit]!=-1) return dp[mission][bit];
    if(mission==n-1){
        for(i=0;i<n;i++){
            if(!(bit&(1<<i))){
                dp[mission][bit]=work[i][mission];
                return dp[mission][bit];
            }
        }
    }
    for(i=0;i<n;i++){
        if(!(bit&(1<<i))){
            tok=(work[i][mission])*(play(mission+1,bit|(1<<i)))/1000000;
            mi=max(mi,tok);
        }
    }
    return dp[mission][bit]=mi;
}
int main()
{
    int i,j;
    scanf(" %d",&n);
    memset(dp,-1,sizeof dp);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf(" %lld",&work[i][j]);
            work[i][j]*=10000;
        }
    }
    printf("%.2lf",(double)play(0,0)/10000);
    return 0;
}
