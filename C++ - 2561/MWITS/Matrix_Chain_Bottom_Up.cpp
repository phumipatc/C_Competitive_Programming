/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int r[12],c[12],dp[12][12];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d %d",&r[i],&c[i]);
    for(int i=1;i<n;i++){
        for(int j=0;j<n-i;j++){
            int minn = 1e9;
            for(int k=j;k<j+i;k++){
                minn = min(minn,dp[j][k]+dp[k+1][j+i]+(r[j]*c[k]*c[i+j]));
            }
            dp[j][j+i] = minn;
        }
    }
    printf("%d\n",dp[0][n-1]);
	return 0;
}
