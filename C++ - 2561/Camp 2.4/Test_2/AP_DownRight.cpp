/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long dp[1010][1010][3];
int main(){
    long long q,r,c,temp;
    scanf("%lld",&q);
    while(q--){
        scanf("%lld %lld",&r,&c);
        for(long long i=1;i<=r;i++){
            for(long long j=1;j<=c;j++){
                scanf("%lld",&temp);
                for(long long k=0;k<=2;k++)
                    dp[i][j][0] = max(dp[i][j][0],max(dp[i-1][j][k],dp[i][j-1][k]));
                dp[i][j][1] = temp+max(dp[i-1][j][0],dp[i][j-1][0]);
                dp[i][j][2] = temp+max(dp[i-1][j][1],dp[i][j-1][1]);
            }
        }
        printf("%lld\n",max(dp[r][c][0],max(dp[r][c][1],dp[r][c][2])));
        memset(dp,0,sizeof dp);
    }
	return 0;
}
