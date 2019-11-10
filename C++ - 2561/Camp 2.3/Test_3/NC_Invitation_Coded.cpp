/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
char a[1010],b[1010];
int dp[1010][1010];
int main(){
    int n;
    for(int q=1;q<=10;q++){
        scanf(" %s",a+1);
        n = strlen(a+1);
        for(int i=1;i<=n;i++){
            a[i] = tolower(a[i]);
            b[n-i+1] = a[i];
        }
        memset(dp,0,sizeof dp);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(a[i] == b[j])    dp[i][j] = dp[i-1][j-1]+1;
                dp[i][j] = max(dp[i][j],max(dp[i-1][j],dp[i][j-1]));
            }
        }
        printf("%d",dp[n][n]%10);
    }
	return 0;
}
