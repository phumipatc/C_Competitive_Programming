/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
char a[260];
int dp[260][260][3];
int segi(int l,int r,int want){
    if(dp[l][r][want]!=-1)  return dp[l][r][want];
    if(l == r){
        dp[l][r][0] = dp[l][r][1] = dp[l][r][2] = 0;
        dp[l][r][a[r]-'0'] = 1;
        return dp[l][r][want];
    }
    for(int k=l;k<r;k++){
        if(want == 0){
            if(segi(l,k,0) && segi(k+1,r,2))
                return dp[l][r][0] = 1;
        }else if(want == 1){
            if(segi(l,k,0) && segi(k+1,r,1))
                return dp[l][r][1] = 1;
            if(segi(l,k,1) && segi(k+1,r,1))
                return dp[l][r][1] = 1;
            if(segi(l,k,1) && segi(k+1,r,2))
                return dp[l][r][1] = 1;
            if(segi(l,k,2) && segi(k+1,r,0))
                return dp[l][r][1] = 1;
            if(segi(l,k,2) && segi(k+1,r,2))
                return dp[l][r][1] = 1;
        }else if(want == 2){
            if(segi(l,k,0) && segi(k+1,r,0))
                return dp[l][r][2] = 1;
            if(segi(l,k,1) && segi(k+1,r,0))
                return dp[l][r][2] = 1;
            if(segi(l,k,2) && segi(k+1,r,1))
                return dp[l][r][2] = 1;
        }
    }
    return dp[l][r][want] = 0;
}
int main(){
    int q = 20,n;
    while(q--){
        scanf("%d %s",&n,a+1);
        memset(dp,-1,sizeof dp);
        if(segi(1,n,0)) printf("yes\n");
        else            printf("no\n");
    }
	return 0;
}
