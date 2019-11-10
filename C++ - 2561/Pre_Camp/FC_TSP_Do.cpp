/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int dp[1510][1510],a[1510][1510],n;
int travel(int l,int r){
    if(r == n || l == n)				return 0;
    if(dp[l][r]!=-1 || dp[r][l]!=-1)    return dp[l][r];
    int next = max(l,r)+1;
    return dp[l][r] = dp[r][l] = min(a[next][l]+travel(next,r),a[r][next]+travel(l,next));
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
    memset(dp,-1,sizeof dp);
    printf("%d\n",travel(1,1));
    return 0;
}
/*
3
0 6 2
6 0 4
2 4 0
*/

