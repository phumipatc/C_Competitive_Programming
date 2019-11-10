/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
vector<long long > g[100010];
long long dp[100010],mark[100010];
void dfs(long long now,long long p){
    mark[now] = 1;
    for(long long i=0;i<g[now].size();i++){
        if(!mark[g[now][i]])    dfs(g[now][i],now);
        if(g[now][i]!=p)        dp[now]*=(dp[g[now][i]]+1),dp[now]%=MOD;
    }
}
int main(){
    long long n,now,u,v,ans = 0;
    cin >> n;
    for(long long i=1;i<n;i++){
        cin >> u >> v;
        g[u].push_back({v});
        g[v].push_back({u});
    }
    for(long long i=1;i<=n;i++)   dp[i] = 1;
    dfs(1,0);
    for(long long i=1;i<=n;i++)
        ans+=dp[i],ans%=MOD;
    cout << ans << endl;
    return 0;
}
