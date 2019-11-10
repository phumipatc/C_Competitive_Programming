/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int dp[550][550];
int main(){
    int q,n,m;

    memset(dp,-1,sizeof dp);
    dp[0][0] = 0;
    for(int i=0;i<=33;i++){
        for(int j=0;j<=33;j++){
            if(i == 0 && j == 0)    continue;
            for(int k=500-i;k>=0;k--){
                for(int l=500-j;l>=0;l--){
                    if(dp[k][l]>=0){
                        dp[k+i][l+j] = max(dp[k+i][l+j],dp[k][l]+1);
                    }
                }
            }
        }
    }
    
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&n,&m);
        printf("%d\n",dp[n][m]);
    }
	return 0;
}
