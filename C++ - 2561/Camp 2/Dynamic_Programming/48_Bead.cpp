/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[110],dp[110][110][2];
int divide(int l,int r){
    if(l == r){
        dp[l][r][1] = a[l];
        return 0;
    }
    if(dp[l][r][0]!=-1) return dp[l][r][0];
    int sum,minn = 1e9;
    for(int k=l;k<r;k++){
        sum = divide(l,k)+divide(k+1,r)+(dp[l][k][1]*dp[k+1][r][1]);
        if(sum<minn){
            minn = sum;
            dp[l][r][1] = (dp[l][k][1]+dp[k+1][r][1])%100;
        }
    }
    return dp[l][r][0] = minn;
}
int main(){
    int q,n;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        memset(dp,-1,sizeof dp);
        printf("%d\n",divide(1,n));
    }
	return 0;
}
