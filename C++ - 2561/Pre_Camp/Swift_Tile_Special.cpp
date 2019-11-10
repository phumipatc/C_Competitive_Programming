/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
#define MOD 9241
using namespace std;
int dp[110][110];
int main(){
    int q,n,k,ans;
    dp[0][0] = 1;
    for(int i=0;i<=100;i++){
        for(int j=0;j<=100;j++){
            dp[i+1][j]+=dp[i][j];   dp[i+1][j]%=MOD;
            dp[i+2][j]+=dp[i][j];   dp[i+2][j]%=MOD;
            dp[i+2][j+1]+=dp[i][j]; dp[i+2][j+1]%=MOD;
            for(int k=3;k<=100;k+=2){   //|_ + -|
                if(i+k>100) break;
                dp[i+k][j+2]+=(2*dp[i][j]);
                dp[i+k][j+2]%=MOD;
            }
            for(int k=4;k<=100;k+=2){   //|_ + -- + _|
                if(i+k>100) break;
                dp[i+k][j+2]+=(2*dp[i][j]);
                dp[i+k][j+2]%=MOD;
            }
        }
    }
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&n,&k);
        ans = 0;
        for(int i=0;i<=k;i++)   ans+=dp[n][i],ans%=MOD;
        printf("%d\n",ans);
    }
	return 0;
}
