/*
TASK: Bipartite
LANG: C++
AUTHOR: PeaTT~
*/
#include <cstdio>
#include <vector>
#include <cstring>
#define pb push_back
#define N 100005
using namespace std;
vector<int > adj[N];
int mark[N];
int dfs(int u, int want)
{
	if(mark[u] == want) return 1;
	else if(mark[u]) return 0;
	mark[u] = want;
	for(int i = 0; i< (int) adj[u].size(); i++)
	{
		int v = adj[u][i];
		if(dfs(v, 3-want) == 0) return 0;
	}
	return 1;
}
int main(){
	int tt,n,m,u,v;
	scanf("%d", &tt);
	while(tt--){
		memset(mark, 0, sizeof mark);
		scanf("%d %d", &n, &m);
		for(int i=0;i<N;i++)
			adj[i].clear();
		for(int i = 0; i< m; i++){
			scanf("%d %d", &u, &v);
			adj[u].pb(v); adj[v].pb(u);
		}
		bool ok = 1;
		for(int i = 1; i<= n; i++){
			if(mark[i] == 0){
				if(dfs(i, 1) == 0){
					ok = 0; break;
				}
			}
		}
		if(ok) puts("yes");
		else puts("no");
	}
	return 0;
}
