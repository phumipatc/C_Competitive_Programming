/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[5010],n,dp[5010][110];
int tree(int now,int k){
    if(now>n)           return 0;
    if(dp[now][k]!=-1)  return dp[now][k];
    if(k == 0)          return dp[now][k] = 0;
    int maxx = -1;
    for(int i=0;i<k;i++)
        maxx = max(maxx,tree(now*2,i)+tree(now*2+1,k-i-1));
    return dp[now][k] = maxx+a[now];
}
int main(){
    int maxx = -1,k;
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    memset(dp,-1,sizeof dp);
    for(int i=1;i<=n;i++)
        maxx = max(maxx,tree(i,k));
    printf("%d\n",maxx);
	return 0;
}
