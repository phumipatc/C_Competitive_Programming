/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long dp[150][150],mul[150][150];
int main(){
    long long q,n,m,i,j,k,l;
    for(i=0;i<=125;i++) dp[i][0]=dp[0][i]=1;
    mul[0][0]=1;
    for(i=1;i<=125;i++){
        mul[0][i]=dp[0][i]+mul[0][i-1];
        mul[0][i]%=9999991;
        mul[i][0]=dp[i][0]+mul[i-1][0];
        mul[i][0]%=9999991;
    }
    for(i=1;i<=125;i++){
        for(j=1;j<=125;j++){
            dp[i][j]=dp[i-1][j]+dp[i][j-1]+mul[i-1][j-1];
            dp[i][j]%=9999991;
            for(k=0;k<=i;k++){
                for(l=0;l<=j;l++){
                    mul[i][j]+=dp[k][l]*dp[i-k][j-l];
                }
            }
        }
    }
    scanf("%lld",&q);
    while(q--){
        scanf("%lld %lld",&n,&m);
        printf("%lld\n",dp[n][m]%9999991);
    }
    return 0;
}
