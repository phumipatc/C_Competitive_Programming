/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[2010],dp[2010][2010];
int main(){
    int n;
    scanf("%d",&n);
    for(int i = 1; i <= n; i++)
        scanf("%d",&a[i]);
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= i; j++){
            if(j == 0)  dp[i][j] = max(dp[i-1][j],dp[i-1][j+2]-a[i]);
            else        dp[i][j] = max(dp[i-1][j-1]+a[i],dp[i-1][j+2]-a[i]);
        }
    }
    printf("%d\n",dp[n][0]);
	return 0;
}
