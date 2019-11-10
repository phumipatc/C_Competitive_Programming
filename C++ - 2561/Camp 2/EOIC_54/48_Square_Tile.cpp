/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int dp[400][400];
int main(){
    int minn;
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
    int q,r,c;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&r,&c);
        printf("%d\n",dp[r][c]);
    }
	return 0;
}
