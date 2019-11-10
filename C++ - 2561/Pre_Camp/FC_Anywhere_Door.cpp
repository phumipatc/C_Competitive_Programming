/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[100010],in[100010],dp[100010],mark[100010];
queue<int > que,ans;
void dfs(int now){
	if(!dp[a[now]])	dfs(a[now]);
	dp[now] = dp[a[now]]+1;
}
int main(){
	int n,v,countt;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		in[a[i]]++;
	}
	for(int i=1;i<=n;i++){
		if(in[i])	continue;
		que.push(i);
	}
	while(!que.empty()){
		v = que.front();
		que.pop();
		in[a[v]]--;
		if(in[a[v]])	continue;
		que.push(a[v]);
	}
	for(int i=1;i<=n;i++){
		if(!in[i])	continue;
		if(mark[i])	continue;
		que.push(i);
		mark[i] = 1;
		countt = 0;
		while(!que.empty()){
			v = que.front();
			que.pop();
			ans.push(v);
			countt++;
			if(mark[a[v]])	continue;
			if(!in[a[v]])	continue;
			mark[a[v]] = 1;
			que.push(a[v]);
		}
		while(!ans.empty()){
			v = ans.front();
			ans.pop();
			dp[v] = countt;
		}
	}
	for(int i=1;i<=n;i++){
		if(dp[i])	printf("%d\n",dp[i]);
		else{
			dfs(i);
			printf("%d\n",dp[i]);
		}
	}
	return 0;
}
