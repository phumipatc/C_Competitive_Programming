/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int dp[310][310],banner[310][310];
int place(int l,int r){
    if(l == r)          return banner[l][r];
    if(dp[l][r]!=-1)    return dp[l][r];
    int maxx = 0;
    for(int i=l;i<r;i++)
        maxx = max(maxx,place(l,i)+place(i+1,r));
    return dp[l][r] = maxx+banner[l][r];
}
int main(){
    memset(dp,-1,sizeof dp);
    int n,m,u,v;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d %d",&u,&v);
        banner[u][v]++;
    }
    printf("%d\n",m-place(1,n));
	return 0;
}
