#include<bits/stdc++.h>
using namespace std;
int dp[100010][25],l[100010],r[100010],costl[100010],costr[100010],mark[100010];
int n,k;
void dfs(int u){
    if(mark[u]) return ;
    dfs(l[u]);  dfs(r[u]);
    for(int i=0; i<=k; i++){
        dp[u][i] = 1e9;
        for(int j=0; j<=i; j++){
            int wantfroml = j,wantfromr = i-j,leftval = 1e9,rightval = 1e9;
            if(dp[l[u]][wantfroml]!=-1)
                leftval = min(costl[u],dp[l[u]][wantfroml]);
            if(dp[r[u]][wantfromr]!=-1)
                rightval = min(costr[u],dp[r[u]][wantfromr]);
            if(leftval!=1e9&&rightval!=1e9)
                dp[u][i] = min(dp[u][i],leftval+rightval);
        }
        int closel=1e9,closer=1e9;
        if(i && dp[r[u]][i-1]!=-1)  closel = min(costr[u],dp[r[u]][i-1]);
        if(i && dp[l[u]][i-1]!=-1)  closer = min(costl[u],dp[l[u]][i-1]);
        if(closel!=1e9)             dp[u][i] = min(dp[u][i],closel);
        if(closer!=1e9)             dp[u][i] = min(dp[u][i],closer);
        if(dp[u][i] == 1e9)         dp[u][i] = -1;
    }
}
int main()
{
    memset(dp,-1,sizeof dp);
    int m,opr,mi=1e9;
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1;i<=m;i++){
        scanf("%d",&opr);
        if(opr == 1)
            scanf("%d %d %d %d",&l[i],&r[i],&costl[i],&costr[i]);
        else
            mark[i]=1;
    }
    for(int i=1;i<=m;i++){
        if(!mark[i])    continue;
        dp[i][0] = n;
    }
    dfs(1);
    for(int j=0; j<=k; j++){
        if(dp[1][j]!=-1)
            mi = min(mi,dp[1][j]);
    }
    printf("%d\n",min(mi,n));
    return 0;
}
