/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
vector< int> g[100100];
int v[100100],dp[100100][2],mark[100100];
void dfs(int now){
	mark[now] = 1;
	dp[now][1] = v[now];
	for(int i=0;i<g[now].size();i++){
		if(mark[g[now][i]])	continue;
		dfs(g[now][i]);
		dp[now][0]+=max(dp[g[now][i]][0],dp[g[now][i]][1]);
		dp[now][1]+=dp[g[now][i]][0];
	}
}
int main(){
	freopen("0_in.txt","r",stdin);
	freopen("0_out.txt","w",stdout);
	int n,st,en;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&v[i]);
	for(int i=1;i<n;i++){
		scanf("%d %d",&st,&en);
		g[st].push_back(en);
		g[en].push_back(st);
	}
	dfs(0);
	printf("%d\n",max(dp[0][0],dp[0][1]));
	return 0;
}
