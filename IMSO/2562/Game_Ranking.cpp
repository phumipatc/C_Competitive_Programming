/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
vector<int > g[5010],g2[5010];
int idx[5010],low[5010],onstack[5010],in[5010];
int comp[5010],lv[5010],num[5010],ans[5010];
int countt = 1,group = 1,maxx = 0;
stack<int > st;
void dfs(int now){
	idx[now] = low[now] = countt++;
	onstack[now] = 1;
	st.push(now);
	for(auto x:g[now]){
		if(!idx[x]){
			dfs(x);
			low[now] = min(low[now],low[x]);
		}else if(onstack[x]){
			low[now] = min(low[now],idx[x]);
		}
	}
	if(idx[now] == low[now]){
		while(st.top()!=now){
			num[group]++;
			comp[st.top()] = group;
			onstack[st.top()] = 0;
			st.pop();
		}
		num[group]++;
		comp[now] = group++;
		onstack[now] = 0;
		st.pop();
	}
}
void dfs2(int now,int lvl){
	maxx = max(maxx,lvl);
	for(auto x:g2[now]){
		in[x]--;
		lv[x] = max(lv[x],lvl+1);
		if(in[x])	continue;
		dfs2(x,lv[x]);
	}
}
int main(){
	int n,p,u,v;
	scanf("%d %d",&n,&p);
	while(p--){
		scanf("%d %d",&u,&v);
		g[u].push_back(v);
	}
	for(int i=0;i<n;i++){
		if(idx[i])	continue;
		dfs(i);
	}
	// printf("%d\n",group);
	for(int i=0;i<n;i++){
		for(auto x:g[i]){
			if(comp[i] == comp[x])	continue;
			g2[comp[i]].push_back(comp[x]);
			in[comp[x]]++;
		}
	}
	for(int i=1;i<group;i++){
		if(in[i])	continue;
		lv[i] = 1;
		dfs2(i,1);
	}
	for(int i=1;i<group;i++)
		ans[lv[i]]+=num[i];
	for(int i=1;i<=maxx;i++)
		printf("%d ",ans[i]);
	return 0;
}