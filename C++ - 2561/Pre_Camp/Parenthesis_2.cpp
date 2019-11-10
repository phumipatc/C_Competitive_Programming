/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long dp[3][205][205],ch;
char a[205];
long long play(long long state,long long l,long long r){
    if(dp[state][l][r]!=-1) return dp[state][l][r];
    if((r-l+1)%2)           return dp[0][l][r]=dp[1][l][r]=0;
    if(r-l+1==2){
        long long res;
        if(a[l] == '?' && a[r] == '?')  res = 3;
        else if(a[l] == '?' || a[r] == '?')
            res = a[l] == '(' || a[l] == '[' || a[l] == '{' || a[r] == '}' || a[r] == ']' || a[r] == ')';
        else
            res = a[l] == '(' && a[r] == ')' || a[l] == '[' && a[r] == ']' || a[l] == '{' && a[r] == '}';
        return dp[0][l][r] = dp[1][l][r] = res;
    }
    if(state == 0){
        long long res;
        if(a[l] == '?' && a[r] == '?')  res = 3;
        else if(a[l] == '?' || a[r] == '?')
            res = a[l] == '(' || a[l] == '[' || a[l] == '{' || a[r] == '}' || a[r] == ']' || a[r] == ')';
        else
            res = a[l] == '(' && a[r] == ')' || a[l] == '[' && a[r] == ']' || a[l] == '{' && a[r] == '}';
        return dp[0][l][r] = (res*play(1,l+1,r-1))%100000;
    }
    long long ans=0,i;
    for(i=l+1; i<=r-2; i++){
        ans+=play(0,l,i)*play(1,i+1,r);
        if(ans>=100000) ch = 1;
        ans%=100000;
    }
    return dp[1][l][r] = (ans+play(0,l,r))%100000;
}
int main(){
    memset(dp,-1,sizeof dp);
    long long n,ans;
    scanf("%lld",&n);
    scanf(" %s",a+1);
    ans = play(1,1,n);
    if(ch)  printf("%05lld",ans);
    else    printf("%lld",ans);
    return 0;
}
