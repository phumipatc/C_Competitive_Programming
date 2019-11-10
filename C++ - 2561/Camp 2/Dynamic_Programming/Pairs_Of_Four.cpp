/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
char a[1010];
int dp[1010][1010];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf(" %c",&a[i]);
    for(int j=1;j<=n;j++){
        for(int i=j-1;i>=1;i--){
            if(a[i] == a[j])    dp[i][j] = dp[i+1][j-1]+1;
            for(int k=i;k<j;k++)
                dp[i][j] = max(dp[i][j],dp[i][k]+dp[k+1][j]);
        }
    }
    printf("%d\n",dp[1][n]);
	return 0;
}
