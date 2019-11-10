/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
vector<int > g[200100];
int a[200100],lv[200100];
void dfs(int now,int state){
	lv[now] = state;
	for(auto x:g[now]){
		if(lv[x])	continue;
		dfs(x,state+1);
	}
}
int main(){
	int n,m,u,v;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<n;i++){
		scanf("%d %d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1,1);
	return 0;
}
