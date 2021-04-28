/*
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Algo	: SCC + DFS
	Status	: Finished
*/
#include<bits/stdc++.h>
#define all(x) begin(x),end(x)
#define allst(x,y) (x).begin()+y,(x).end()
#define sz(x) (int)(x).size()
#define decp(x) fixed << setprecision(x)
#define MOD (LL )(1e9+7)
using namespace std;
using LL = long long;
using PII = pair<int ,int >;
using PLL = pair<long long ,long long >;
const int dir4[2][4] = {{1,-1,0,0},{0,0,1,-1}};
const int dir8[2][8] = {{-1,-1,-1,0,1,1,1,0},{-1,0,1,1,-1,0,1,-1}};
const int MAX_INT = 1e9;
const LL MAX_LL = 1e18;
LL modN(LL a,LL b,LL c = MOD){
	if(b == 0)	return 1;
	if(b == 1)	return a%c;
	LL now = modN(a,b/2);
	if(b&1)	return (((now*now)%c)*(a%c))%c;
	else	return (now*now)%c;
}
char c[10010];
vector<int > g[10010],scc[10010],gn[10010];
string str[10010];
int idx[10010],low[10010],onstack[10010],mark[10010],comp[10010];
stack<int > st;
int cnt,cnt2 = 1;
void dfs(int u){
	idx[u] = low[u] = ++cnt;
	mark[u] = 1;
	onstack[u] = 1;
	st.push(u);
	for(auto x:g[u]){
		if(!mark[x]){
			dfs(x);
			low[u] = min(low[u],low[x]);
		}else if(onstack[x]){
			low[u] = min(low[u],idx[x]);
		}
	}
	if(idx[u] == low[u]){
		while(st.top()!=u){
			int now = st.top();
			st.pop();
			comp[now] = cnt2;
			scc[cnt2].push_back(now);
			str[cnt2].push_back(c[now]);
			onstack[now] = 0;
		}
		st.pop();
		onstack[u] = 0;
		scc[cnt2].push_back(u);
		str[cnt2].push_back(c[u]);
		sort(all(str[cnt2]));
		comp[u] = cnt2++;
	}
}
int n,m;
string dp[10010];
int path[10010];
string find_ans(int u){
	if(mark[u])	return dp[u];
	mark[u] = 1;
	if(u == comp[n]){
		path[u] = 1;
		return dp[u] = str[u];
	}
	string now = "";
	for(auto x:gn[u]){
		string nxt = find_ans(x);
		if(!path[x])	continue;
		path[u] = 1;
		if(sz(now)<sz(nxt))						now = nxt;
		else if(sz(now) == sz(nxt) && now>nxt)	now = nxt;
	}
	return dp[u] = str[u]+now;
}
void solve(){
	cin >> n >> m;
	for(int i=1;i<=n;i++)
		cin >> c[i];
	while(m--){
		int u,v;
		cin >> u >> v;
		g[u].push_back(v);
	}
	dfs(1);
	for(int i=1;i<=cnt2;i++)
		for(auto x:scc[i])
			for(auto y:g[x])
				gn[i].push_back(comp[y]);
	for(int i=1;i<=cnt2;i++){
		sort(all(gn[i]));
		gn[i].resize(unique(all(gn[i]))-gn[i].begin());
	}
	memset(mark,0,sizeof mark);
	cout << find_ans(comp[1]) << '\n';
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int q = 1;
	// cin >> q;
	for(int Q=1;Q<=q;Q++){
		// cout << "Case #" << Q << ": ";
		solve();
	}
	return 0;
}
/*
5 6
ABAAB
1 2
1 3
2 5
3 5
4 5
5 4
*/