/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int dp[2][10010];
int main(){
    int n,r,k;
    scanf("%d %d %d",&n,&r,&k);
    dp[0][0] = 1;
    for(int i=1;i<=n;i++){
        dp[i%2][0] = dp[i%2][i] = 1;
        for(int j=1;j<i;j++){
            dp[i%2][j] = (dp[(i+1)%2][j-1]+dp[(i+1)%2][j])%k;
        }
    }
    printf("%d\n",dp[n%2][r]);
	return 0;
}
