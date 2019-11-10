/*
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
vector<int > g[1010];
int dp[1010][3];
void dfs(int now,int p){
    dp[now][1]++;
    int sum = 1;
    for(auto x:g[now]){
        if(x == p)  continue;
        dfs(x,now);
        dp[now][0]+=max(dp[x][0],max(dp[x][1],dp[x][2]));
        dp[now][1]+=dp[x][0];
        sum+=dp[x][0];
    }
    dp[now][2] = sum;
    for(auto x:g[now]){
        if(x == p)  continue;
        dp[now][2] = max(dp[now][2],sum-dp[x][0]+dp[x][1]);
    }
    // printf("%d : %d %d %d\n",now,dp[now][0],dp[now][1],dp[now][2]);
}
int main(){
    int q,n,u,v;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        for(int i=1;i<n;i++){
            scanf("%d %d",&u,&v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        memset(dp,0,sizeof dp);
        dfs(1,0);
        printf("%d\n",max(dp[1][0],max(dp[1][1],dp[1][2])));
        for(int i=1;i<=n;i++)
            g[i].clear();
    }
    return 0;
}
/*
2
7
1 2
2 3
4 2
2 5
5 6
6 7
4
1 2
2 4
4 3

*/