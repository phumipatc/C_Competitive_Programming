/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int w[5005],t[5005],dp[5005][15005];
int main(){
    int k,n;
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",&w[i]);
    for(int i=1;i<=n;i++)
        scanf("%d",&t[i]),t[i] = (t[i]+1)*8;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            if(t[i]<=j)
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-t[i]]+w[i]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    printf("%d\n",dp[n][k]);
    return 0;
}
