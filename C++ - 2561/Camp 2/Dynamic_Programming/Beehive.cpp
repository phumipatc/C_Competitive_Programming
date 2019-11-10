/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int dp[1010][1010][2];
int main(){
    int r,c,maxx = -1e9,countt;
    scanf("%d %d",&r,&c);
    for(int i=1;i<=r;i++)
        for(int j=1;j<=c;j++)
            scanf("%d",&dp[i][j][0]);
    for(int j=1;j<=c;j++)
        dp[r][j][1] = 1;
    for(int i=r-1;i>=1;i--){
        for(int j=1;j<=c;j++){
            if(i%2 == 1){
                if(dp[i+1][j-1][0]>dp[i+1][j][0]){
                    dp[i][j][0]+=dp[i+1][j-1][0];
                    dp[i][j][1] = dp[i+1][j-1][1];
                }else if(dp[i+1][j][0]>dp[i+1][j-1][0]){
                    dp[i][j][0]+=dp[i+1][j][0];
                    dp[i][j][1] = dp[i+1][j][1];
                }else{
                    dp[i][j][0]+=dp[i+1][j][0];
                    dp[i][j][1] = dp[i+1][j-1][1]+dp[i+1][j][1];
                }
            }else{
                if(dp[i+1][j+1][0]>dp[i+1][j][0]){
                    dp[i][j][0]+=dp[i+1][j+1][0];
                    dp[i][j][1] = dp[i+1][j+1][1];
                }else if(dp[i+1][j][0]>dp[i+1][j+1][0]){
                    dp[i][j][0]+=dp[i+1][j][0];
                    dp[i][j][1] = dp[i+1][j][1];
                }else{
                    dp[i][j][0]+=dp[i+1][j][0];
                    dp[i][j][1] = dp[i+1][j+1][1]+dp[i+1][j][1];
                }
            }
        }
    }
    for(int j=1;j<=c;j++){
        if(maxx<dp[1][j][0]){
            maxx = dp[1][j][0];
            countt = dp[1][j][1];
        }else if(maxx == dp[1][j][0]){
            countt+=dp[1][j][1];
        }
    }
    printf("%d %d\n",maxx,countt);
	return 0;
}
