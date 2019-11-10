/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int dp[5010][15010],a[5010];
int main(){
    int n,k,temp;
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++){
        scanf("%d",&temp);
        temp++,temp*=8;
        for(int j=1;j<=k;j++){
            if(temp>j)  dp[i][j] = dp[i-1][j];
            else        dp[i][j] = max(dp[i-1][j],dp[i-1][j-temp]+a[i]);
        }
    }
    printf("%d\n",dp[n][k]);
	return 0;
}
