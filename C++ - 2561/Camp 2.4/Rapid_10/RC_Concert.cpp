/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int v,w;
    bool operator < (const A&o) const{
        if(w!=o.w)  return w<o.w;
        else        return v<o.v;
    }
};
vector<A > g[300010],com;
int dis[300010],mark[300010],dp[300010];
int path = 1,n;
void dfs(int now){
    int ch = 1;
    if(path)    mark[now] = 1;
    for(auto x:g[now]){
        ch = 0;
        dis[x.v] = dis[now]+x.w;
        dfs(x.v);
    }
    if(ch){
        if(now == n)    path = 0;
        com.push_back({now,dis[now]});
    }
    if(path)    mark[now] = 0;
}
void sum_up(int now){
    for(auto x:g[now]){
        sum_up(x.v);
        dp[now]+=dp[x.v];
    }
}
int main(){
    int u,v,w;
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        scanf("%d %d %d",&u,&v,&w);
        g[v].push_back({u,w});
        dis[i] = 1e9;
    }
    dis[n] = 1e9,dis[1] = 0;
    dfs(1);
    sort(com.begin(),com.end());
    int pos = 1;
    for(auto x:com){
        if(x.v == n)    break;
        pos++;
        dp[x.v]++;
    }
    sum_up(1);
    int ans = 0;
    for(int i=2;i<n;i++){
        if(mark[i]) continue;
        ans = max(ans,dp[i]);
    }
    printf("%d\n",pos - ans);
	return 0;
}
/*
8
2 1 5
3 2 12
4 1 17
5 2 13
6 3 6
7 4 7
8 4 15
*/