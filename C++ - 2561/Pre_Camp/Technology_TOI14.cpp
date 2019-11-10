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
        return w>o.w;
    }
};
A now;
priority_queue<A > heap;
int in[100010],a[100010],dp[100010],countt[10010];
vector<int > g[100010];
void dfs(int now){
    dp[now] = a[now];
    for(auto x:g[now]){
        if(!dp[x])  dfs(x);
        dp[now] = min(dp[now],dp[x]);
    }
}
int main(){
    int n,k,t,u,v;
    scanf("%d %d %d",&n,&k,&t);
    for(int i=1;i<=n;i++){
        scanf("%d %d",&a[i],&u);
        countt[a[i]]++;
        in[i] = u;
        while(u--){
            scanf("%d",&v);
            g[v].push_back(i);
        }
    }
    for(int i=1;i<=n;i++){
        if(in[i])   continue;
        dfs(i);
    }
    for(int i=1;i<=n;i++){
        if(in[i])   continue;
        heap.push({i,dp[i]});
    }
    while(!heap.empty() && t--){
        now = heap.top();
        heap.pop();
        countt[a[now.v]]--;
        for(auto x:g[now.v]){
            in[x]--;
            if(in[x])   continue;
            heap.push({x,dp[x]});
        }
    }
    for(int i=1;i<=k;i++){
        if(!countt[i])  continue;
        if(i == 1)  printf("-1\n");
        else        printf("%d\n",i-1);
        return 0;
    }
    printf("%d\n",k);
	return 0;
}
