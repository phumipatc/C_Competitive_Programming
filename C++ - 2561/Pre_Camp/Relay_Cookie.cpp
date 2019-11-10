/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
vector<int > g[100010];
int k;
int p[100010],a[100010],dp[100010][25];
void dfs(int now){
    for(auto x:g[now]){
        if(x == p[now]) continue;
        p[x] = now;
        dfs(x);
        for(int i=1;i<=k;i++)
            dp[now][i]+=dp[x][i-1];
    }
    dp[now][0] = a[now];
}
void dfs2(int now){
    if(now!=1){
        for(int i=k;i>=1;i--){
            dp[now][i]+=dp[p[now]][i-1];
            if(i>=2)    dp[now][i]-=dp[now][i-2];
        }
    }
    for(auto x:g[now]){
        if(x == p[now]) continue;
        dfs2(x);
    }
}
int main(){
    int n,u,v,ans;
    scanf("%d %d",&n,&k);
    for(int i=1;i<n;i++){
        scanf("%d %d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    dfs(1);
    dfs2(1);
    for(int i=1;i<=n;i++){
        ans = 0;
        for(int j=0;j<=k;j++)
            ans+=dp[i][j];
        printf("%d\n",ans);
    }
	return 0;
}
