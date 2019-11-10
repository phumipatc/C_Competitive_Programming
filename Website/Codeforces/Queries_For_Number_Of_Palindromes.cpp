/*
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
char a[5010];
int dp[5010][5010],p[5010][5010];
int palindrome(int l,int r){
    if(l>=r)            return p[l][r] = 1;
    if(p[l][r]!=-1)     return p[l][r];
    if(a[l] == a[r])    return p[l][r] = palindrome(l+1,r-1);
    else                return p[l][r] = 0;
}
int divide(int l,int r){
    if(l>r)             return 0;
    if(l == r)          return dp[l][r] = 1;
    if(dp[l][r]!=-1)    return dp[l][r];
    int ret = 0;
    int ll = l,rr = r;
    ret = palindrome(l,r)+divide(l,r-1)+divide(l+1,r)-divide(l+1,r-1);
    return dp[l][r] = ret;
}
int main(){
    int n,q,l,r;
    scanf(" %s",a+1);
    n = strlen(a+1);
    memset(p,-1,sizeof p);
    memset(dp,-1,sizeof dp);
    dp[1][n] = divide(1,n);
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&l,&r);
        printf("%d\n",dp[l][r]);
    }
    return 0;
}