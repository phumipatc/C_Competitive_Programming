/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int v,w;
};
struct B{
    int l,r;
};
vector<A > g[110];
B tree[110];
int dp[110][110],durian[110],mark[110];
void dfs(int now){
    mark[now] = 1;
    for(auto x:g[now]){
        if(mark[x.v])   continue;
        durian[x.v] = x.w;
        if(!tree[now].l)    tree[now].l = x.v;
        else                tree[now].r = x.v;
        dfs(x.v);
    }
}
int cut(int now,int k){
    if(k == 0)          return 0;
    if(now == 0)        return 0;
    if(dp[now][k]!=-1)  return dp[now][k];
    int maxx = -1;
    for(int i=0;i<k;i++){
        maxx = max(maxx,cut(tree[now].l,i)+cut(tree[now].r,k-i-1));
    }
    return dp[now][k] = maxx+durian[now];
}
int main(){
    int n,k,u,v,w;
    scanf("%d %d",&n,&k);
    for(int i=1;i<n;i++){
        scanf("%d %d %d",&u,&v,&w);
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    dfs(1);
    memset(dp,-1,sizeof dp);
    printf("%d\n",cut(1,k+1));
	return 0;
}
