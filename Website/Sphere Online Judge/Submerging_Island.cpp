/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
vector<int > g[10100];
int num[10100],low[10100],mark[10100],idx = 1,countt,countt2;
void dfs(int now,int last){
	// printf("%d\n",now);
	num[now] = low[now] = idx++;
	mark[now] = 1;
	int ch = 0;
	for(int i=0;i<g[now].size();i++){
		if(g[now][i] == last)	continue;
		if(mark[g[now][i]]){
			low[now] = min(low[now],num[g[now][i]]);
		}else{
			if(now == 1)	countt2++;
			dfs(g[now][i],now);
			if(num[now]<=low[g[now][i]] && now!=1)	ch = 1;
			low[now] = min(low[now],low[g[now][i]]);
		}
	}
	if(ch)	countt++;
}
int main(){
	// freopen("0_in.txt","r",stdin);
	// freopen("0_out.txt","w",stdout);
	int n,m,u,v;
	scanf("%d %d",&n,&m);
	while(n!=0 && m!=0){
		for(int i=1;i<=m;i++){
			scanf("%d %d",&u,&v);
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfs(1,1);
		// for(int i=1;i<=n;i++)
			// printf("%d %d\n",num[i],low[i]);
		if(countt2>1)	countt++;
		printf("%d\n",countt);
		memset(mark,0,sizeof mark);
		memset(num,0,sizeof num);
		memset(low,0,sizeof low);
		for(int i=1;i<=n;i++)
			g[i].clear();
		idx = 1,countt = countt2 = 0;
		scanf("%d %d",&n,&m);
	}
	return 0;
}
