/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include <bits/stdc++.h>
using namespace std;
vector <int> g[50010];
int dp[50010][510];
int ans,k;
void dfs(int u, int p){
    dp[u][0] = 1;
    for (auto x : g[u]){
        if (x == p) continue;
        dfs(x,u);
        for(int j = 1; j <= k; j++)
            ans += dp[u][j-1]*dp[x][k-j];
        for(int j = 1; j <= k; j++)
            dp[u][j] += dp[x][j-1];
    }
}
int main(){
    int n,u,v;
    scanf("%d %d",&n,&k);
    for(int i = 1; i < n; i++){
        scanf("%d %d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0);
    printf("%d",ans);
}