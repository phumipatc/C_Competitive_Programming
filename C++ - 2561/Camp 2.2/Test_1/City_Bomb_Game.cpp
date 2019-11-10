/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
vector<int > g[1010];
int dp[1010],mark[1010],leaf[1010];
void chleaf(int now){
	leaf[now] = mark[now] = 1;
	for(auto x:g[now]){
		if(mark[x])	continue;
		leaf[now] = 0;
		chleaf(x);
	}
}
void dfs(int now,int state){
	mark[now] = 1;
	for(auto x:g[now]){
		if(mark[x])	continue;
		dfs(x,!state);
		if(state == 0){
			if(dp[x]){
				dp[now] = 1;
				return ;
			}else{
				dp[now] = 0;
			}
		}else{
			if(!dp[x]){
				dp[now] = 0;
				return ;
			}else{
				dp[now] = 1;
			}
		}
	}
	if(leaf[now]){
		if(state%2)	dp[now] = 1;
	}
}
int main(){
	int n,k,u,v;
	scanf("%d %d",&n,&k);
	for(int i=1;i<n;i++){
		scanf("%d %d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int i=1;i<=n;i++)
		sort(g[i].begin(),g[i].end());
	chleaf(k);
	memset(mark,0,sizeof mark);
	mark[k] = 1;
	for(auto x:g[k]){
		dfs(x,1);
		if(dp[x]){
			printf("First player wins traveling to city %d\n",x);
			return 0;
		}
	}
	printf("First player loses\n");
	return 0;
}
