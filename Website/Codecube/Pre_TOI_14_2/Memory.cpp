/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[5005],b[5005],minn[5005],dp[2][5005];
int main(){
    int i,n,m,k,ans = 0;
    cin >> n >> m >> k;
    for(i=1;i<=n;i++)
        cin >> a[i];
    for(i=1;i<=m;i++){
        cin >> b[i];
        dp[0][i] = minn[i] = i;
    }
    for(int i=1;i<=n;i++){
        dp[i&1][0] = 1;
        for(int j=1;j<=m;j++){
            if(a[i] == b[j])
                dp[i&1][j] = dp[(i&1)^1][j-1];
            else
                dp[i&1][j] = 1e9;
            dp[i&1][j] = min(dp[i&1][j],min(dp[i&1][j-1]+1,min(dp[(i&1)^1][j-1]+1,minn[j]+1)));
            minn[j] = min(minn[j],dp[i&1][j]);
            if(dp[i&1][j]<=k)   ans = max(ans,j);
        }
    }
    printf("%d\n",ans);
    return 0;
}
