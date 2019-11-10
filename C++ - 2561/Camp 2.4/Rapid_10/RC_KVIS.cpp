/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[510],dp[510][510];
int main(){
    int n,maxk;
    scanf("%d %d",&n,&maxk);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        a[i]+=a[i-1];
    }
    for(int i=0;i<=n;i++)
        for(int j=0;j<=maxk;j++)
            dp[i][j] = 1e9;
    dp[0][0] = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            for(int k=1;k<=maxk;k++){
                int all = i-j+1,num = a[i]-a[j-1];
                dp[i][k] = min(dp[i][k],dp[j-1][k-1]+(num*(all-num)));
                // printf("%d %d %d %d\n",i,j,k,dp[i][k]);
            }
        }
    }
    printf("%d\n",dp[n][maxk]);
	return 0;
}