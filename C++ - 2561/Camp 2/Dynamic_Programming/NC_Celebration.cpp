/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
#define INF 1e9;
using namespace std;
vector<int > g[10010];
int a[10010],dp[10010][4],mark[10010];
void dfs(int now){
    mark[now] = 1;
    if(g[now].size() == 1 && mark[g[now][0]]){
        dp[now][0] = a[now];
        dp[now][1] = INF;
        dp[now][2] = 0;
        return ;
    }
    printf("%d\n",now);
    int ch1 = 0,ch2 = 0;
    for(auto x:g[now]){
        if(mark[x]) continue;
        dfs(x);
        printf("to %d\n",x);
        dp[now][0]+=min(dp[x][0],min(dp[x][1],dp[x][2]));
        dp[now][2]+=dp[x][1];
    }
    dp[now][0]+=a[now];
    for()
    if(dp[now][0]>1e9)  dp[now][0] = 1e9;
    if(dp[now][1]>1e9)  dp[now][1] = 1e9;
    if(dp[now][2]>1e9)  dp[now][2] = 1e9;
    printf("%d : %d %d %d\n",now,dp[now][0],dp[now][1],dp[now][2]);
}
int main(){
    int n,u,v;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<n;i++){
        scanf("%d %d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);
    printf("%d\n",min(dp[1][0],dp[1][1]));
	return 0;
}
/*
6
4 9 1 20 5 3
2 1
3 2
2 4
5 4
4 6
*/
