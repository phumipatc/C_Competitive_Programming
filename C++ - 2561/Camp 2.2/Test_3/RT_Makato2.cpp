/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
vector<int > g[100010];
int val[100010],mark[100010],XOR[100010],dp[100010],p[100010];
void dfs(int now){
    mark[now] = 1;
    XOR[now]^=val[now];
    for(auto x:g[now]){
        if(mark[x]) continue;
        dfs(x);
        p[x] = now;
        XOR[now]^=XOR[x];
        dp[now]+=XOR[x];
    }
}
int main(){
    int n,ans = 1e9,u,v;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&val[i]);
    for(int i=1;i<n;i++){
        scanf("%d %d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);
    for(int i=1;i<=n;i++)
        ans = min(ans,dp[i]+(XOR[1]^XOR[i]));
    printf("%d\n",ans);
	return 0;
}
