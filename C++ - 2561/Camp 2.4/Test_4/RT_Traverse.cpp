/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
vector<int > g[10];
int mark[10];
int n,ans = 0,countt = 0;
void dfs(int now){
	mark[now] = 1;
	countt++;
	if(countt == n)	ans++;
	for(auto x:g[now]){
		if(mark[x])	continue;
		dfs(x);
	}
	countt--;
	mark[now] = 0;
}
int main(){
    int m,u,v;
    cin >> n >> m;
    while(m--){
        cin >> u >> v;
        g[u].push_back(v);
		g[v].push_back(u);
    }
	dfs(1);
	cout << ans << endl;
	return 0;
}