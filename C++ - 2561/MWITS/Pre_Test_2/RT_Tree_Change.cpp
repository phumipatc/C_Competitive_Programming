/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
vector<int > g[1010];
int dp[1010][2];
void dfs(int now,int p){
    int c1 = 1e9,c2 = 1e9;
    for(auto x:g[now]){
        if(x == p)  continue;
        dfs(x,now);
        dp[now][0]+=dp[x][0]+1;
        if(dp[x][1]-(dp[x][0]+1)<=c1){
            c2 = c1;
            c1 = dp[x][1]-(dp[x][0]+1);
        }else if(dp[x][1]-(dp[x][0]+1)<c2){
            c2 = dp[x][1]-(dp[x][0]+1);
        }
    }
    dp[now][1] = min(dp[now][0],dp[now][0]+c1+c2);
}
int main(){
    int q,n,u,v,minn;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        for(int i=1;i<n;i++){
            scanf("%d %d",&u,&v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        minn = 1e9;
        for(int i=1;i<=n;i++){
            dfs(i,0);
            minn = min(minn,dp[i][1]);
            memset(dp,0,sizeof dp);
        }
        printf("%d\n",minn);
        for(int i=1;i<=n;i++)
            g[i].clear();
    }
	return 0;
}
