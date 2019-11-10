/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
vector<long long > g[100010],child;
long long dp[100010],l[100010],r[100010],sum[100010],ans[100010];
long long n,m;
void dfs(long long now,long long p){
    dp[now] = 1;
    for(auto x:g[now]){
        if(x == p)  continue;
        dfs(x,now);
        dp[now]*=dp[x];
        dp[now]%=m;
    }
    dp[now]++;
    dp[now]%=m;
    child.clear();
    child.push_back(0);
    for(auto x:g[now]){
        if(x == p)  continue;
        child.push_back(x);
    }
    l[0] = r[child.size()] = 1;
    for(long long i=1;i<child.size();i++)
        l[i] = (l[i-1]*dp[child[i]])%m;
    for(long long i=child.size()-1;i>0;i--)
        r[i] = (r[i+1]*dp[child[i]])%m;
    for(long long i=1;i<child.size();i++)
        sum[child[i]] = (l[i-1]*r[i+1])%m;
}
void dfs2(long long now,long long p){
    if(now == 1)    ans[now] = 1;
    else            ans[now] = ((ans[p]*sum[now])+1)%m;
    for(auto x:g[now]){
        if(x == p)  continue;
        dfs2(x,now);
    }
}
int main(){
    long long u,v;
    scanf("%lld %lld",&n,&m);
    for(long long i=1;i<n;i++){
        scanf("%lld %lld",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0);
    dfs2(1,0);
    for(long long i=1;i<=n;i++)
        printf("%lld\n",ans[i]*(dp[i]-1+m)%m);
	return 0;
}