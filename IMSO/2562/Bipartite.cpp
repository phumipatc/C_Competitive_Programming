/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
vector<int > g[100010];
int col[100010];
bool dfs(int u,int c){
	if(col[u]){
		if(col[u] == c)	return true;
		else			return false;
	}
	col[u] = c;
	for(auto x:g[u]){
		if(!dfs(x,3-c))
			return false;
	}
	return true;
}
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int q,n,m,u,v;
	cin >> q;
	while(q--){
		cin >> n >> m;
		while(m--){
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		int ans = 1;
		for(int i=1;i<=n;i++){
			if(col[i])	continue;
			if(!dfs(i,1)){
				ans = 0;
				break;
			}
		}
		if(ans)	cout << "yes\n";
		else	cout << "no\n";
		for(int i=1;i<=n;i++)
			g[i].clear();
		memset(col,0,sizeof col);
	}
	return 0;
}