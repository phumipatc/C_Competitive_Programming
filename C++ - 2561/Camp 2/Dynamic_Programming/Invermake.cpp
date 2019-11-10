/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int dp[1010][10010];
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    dp[1][0] = 1;
    for(int i=2;i<=n;i++){
        dp[i][0] = 1;
        for(int j=1;j<=k;j++){
            dp[i][j] = dp[i-1][j]+dp[i][j-1];
            if(j>=i)    dp[i][j]-=dp[i-1][j-i];
            dp[i][j] = ((dp[i][j]%MOD)+MOD)%MOD;
        }
        cout << endl;
    }
    printf("%d\n",dp[n][k]);
	return 0;
}
