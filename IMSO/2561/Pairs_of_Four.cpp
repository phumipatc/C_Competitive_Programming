/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
char a[1010];
int dp[1010][1010];
int play(int l,int r){
    if(l>=r)            return 0;
    if(dp[l][r]!=-1)    return dp[l][r];
    int ans = -1;
    for(int k=l;k<r;k++)
        ans = max(ans,play(l,k)+play(k+1,r));
    if(a[l] == a[r])    ans = max(ans,play(l+1,r-1)+1);
    return dp[l][r] = ans;
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf(" %c",&a[i]);
    memset(dp,-1,sizeof dp);
    printf("%d\n",play(1,n));
    return 0;
}
