/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[210],b[210],c[210],dp[210][210][210][2];
int n;
int play(int na,int nb,int nc,int state){
    if(dp[na][nb][nc][state]!=-1)   return dp[na][nb][nc][state];
    int ans;
    if(state == 0){
        ans = 0;
        if(na>0)    ans = max(ans,play(na-1,nb,nc,1)+a[na]);
        if(nb>0)    ans = max(ans,play(na,nb-1,nc,1)+b[nb]);
        if(nc>0)    ans = max(ans,play(na,nb,nc-1,1)+c[nc]);
    }else{
        ans = 1e9;
        if(na>0)    ans = min(ans,play(na-1,nb,nc,0));
        if(nb>0)    ans = min(ans,play(na,nb-1,nc,0));
        if(nc>0)    ans = min(ans,play(na,nb,nc-1,0));
        if(ans == 1e9)  ans = 0;
    }
    // printf("%d %d %d %d : %d\n",na,nb,nc,state,ans);
    return dp[na][nb][nc][state] = ans;
}
int main(){
    int sum = 0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]),sum+=a[i];
    for(int i=1;i<=n;i++)
        scanf("%d",&b[i]),sum+=b[i];
    for(int i=1;i<=n;i++)
        scanf("%d",&c[i]),sum+=c[i];
    memset(dp,-1,sizeof dp);
    printf("%d %d\n",play(n,n,n,0),sum-play(n,n,n,0));
	return 0;
}
