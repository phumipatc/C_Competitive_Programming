/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int dp[100010][320],qs[100010];
int main(){
    int n;
    scanf("%d",&n);
    int sq = sqrt(n);
    for(int i=0;i<=n;i++)
        for(int j=1;j<=sq;j++)
            dp[i][j] = -1e9;
	return 0;
}