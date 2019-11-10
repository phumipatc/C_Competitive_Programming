/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int dp[360][360],minn;
int main(){
    for(int i=1;i<=350;i++){
        for(int j=1;j<=350;j++){
            if(i == j){
                dp[i][j] = 1;
                continue;
            }
            minn = 1e9;
            for(int k=1;k<i;k++)
                minn = min(minn,dp[k][j]+dp[i-k][j]);
            for(int k=1;k<j;k++)
                minn = min(minn,dp[i][k]+dp[i][j-k]);
            dp[i][j] = minn;
        }
    }
    int q,n,m;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&n,&m);
        printf("%d\n",dp[n][m]);
    }
	return 0;
}
