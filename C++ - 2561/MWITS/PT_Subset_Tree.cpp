/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long a[100010],dp[100010][2];
vector<long long > g[100010];
void dfs(long long now,long long p){
    for(auto x:g[now]){
        if(x == p)  continue;
        dfs(x,now);
        dp[now][0]+=max(dp[x][0],dp[x][1]);
        dp[now][1]+=dp[x][0];
    }
    dp[now][1]+=a[now];
    return ;
}
int main(){
    long long q,n,u,v;
    scanf("%lld",&q);
    while(q--){
        scanf("%lld",&n);
        for(long long i=1;i<=n;i++)
            scanf("%lld",&a[i]);
        for(long long i=1;i<n;i++){
            scanf("%lld %lld",&u,&v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        memset(dp,0,sizeof dp);
        dfs(1,0);
        printf("%lld\n",max(dp[1][0],dp[1][1]));
        for(long long i=1;i<=n;i++)
            g[i].clear();
    }
	return 0;
}
