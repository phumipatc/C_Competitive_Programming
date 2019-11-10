/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int price[10010],dp[10010][3];
vector<int > g[10010];
int dfs(int now,int p,int state){
    if(dp[now][state]!=-1)  return dp[now][state];
    if(g[now].size() == 1 && g[now][0] == p){
        if(state == 0)  return dp[now][state] = 0;
        if(state == 1)  return dp[now][state] = price[now];
        if(state == 2)  return dp[now][state] = 1e9;
    }
    int sum = 0,minn = 1e9;
    if(state == 1)  sum+=price[now];
    for(auto x:g[now]){
        if(x == p)  continue;
        if(state == 0)  sum+=min(dfs(x,now,1),dfs(x,now,2));
        if(state == 1)  sum+=min(dfs(x,now,0),min(dfs(x,now,1),dfs(x,now,2)));
        if(state == 2){
            int temp = dfs(x,now,1),tempp = dfs(x,now,2);
            if(temp<=tempp) minn = 0;
            else            minn = min(minn,temp-tempp);
            sum+=min(temp,tempp);
        }
    }
    if(state == 2)  return dp[now][state] = sum+minn;
    else            return dp[now][state] = sum;
}
int main(){
    int n,u,v;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&price[i]);
    for(int i=1;i<n;i++){
        scanf("%d %d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    memset(dp,-1,sizeof dp);
    printf("%d\n",min(dfs(1,0,1),dfs(1,0,2)));
	return 0;
}
