/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
#define MOD 55555
using namespace std;
int dp[2][10100];
int main(){
    int n;
    cin >> n;
    for(int i=0;i<=n;i++){
        dp[i%2][0] = dp[i%2][i] = 1;
        for(int j=1;j<i;j++)
            dp[i%2][j] = (dp[(i+1)%2][j-1]+dp[(i+1)%2][j])%MOD;
    }
    for(int i=0;i<=n;i++)
        printf("%d ",dp[n%2][i]);
	return 0;
}
