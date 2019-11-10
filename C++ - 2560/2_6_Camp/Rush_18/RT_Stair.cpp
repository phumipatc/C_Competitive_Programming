/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int dp[2000000][2];
int main(){
    int q,n;
    dp[0][0] = dp[1][0] = 1;
    for(int i=2;i<=2000000;i++)
        dp[i][0] = (dp[i-1][0]+dp[i-2][0])%MOD;
    for(int i=1;i<=1000000;i++)
        dp[i][1] = dp[2*i][0]%MOD;
    for(int i=1;i<=1000000;i++){
        dp[i][1] = (dp[i][1]+dp[i-1][1])%MOD;
        if(i>1)
            dp[i][1] = (dp[i][1]+dp[i-2][1])%MOD;
    }
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        printf("%d\n",(dp[n][0]+dp[n][1])%MOD);
    }
    return 0;
}
