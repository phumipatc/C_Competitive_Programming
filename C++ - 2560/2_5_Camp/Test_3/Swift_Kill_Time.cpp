/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int u,v,c,w;
};
A a[5005];
int dp[5005][2005];
int main(){
    int n,m,k,ans = -1,st,en;
    scanf("%d %d %d %d %d",&n,&m,&k,&st,&en);
    for(int i=1;i<=m;i++)
        scanf("%d %d %d %d",&a[i].u,&a[i].v,&a[i].c,&a[i].w);
    memset(dp,-1,sizeof dp);
    dp[st][0] = 0;
    for(int i=1;i<=k;i++){
        for(int j=1;j<=m;j++){
            if(i-a[j].w<0)  continue;
            if(dp[a[j].u][i-a[j].w]!=-1)
                dp[a[j].v][i] = max(dp[a[j].v][i],dp[a[j].u][i-a[j].w]+a[j].c);
            if(dp[a[j].v][i-a[j].w]!=-1)
                dp[a[j].u][i] = max(dp[a[j].u][i],dp[a[j].v][i-a[j].w]+a[j].c);

        }
    }
    for(int i=1;i<=k;i++)
        ans = max(ans,dp[en][i]);
    if(ans == -1)   printf("Impossible\n");
    else            printf("%d\n",ans);
    return 0;
}
