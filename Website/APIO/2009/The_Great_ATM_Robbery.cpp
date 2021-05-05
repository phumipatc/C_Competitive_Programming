/*
	Task	: The_Great_ATM_Robbery
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Created	: 01 May 2021 [08:02]
	Algo	: SCC
	Status	: Finished
*/
#include<bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < (b); ++i)
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
	LL now = modN(a,b/2,c);
	if(b&1)	return (((now*now)%c)*(a%c))%c;
	else	return (now*now)%c;
}
const int N = 500010;
int idx[N],low[N],comp[N],onst[N];
stack<int > st;
vector<int > g[N],ng[N];
vector<int > rest;
int val[N],cval[N],mark[N];
int cnt,compnum;
void scc(int u){
	idx[u] = low[u] = ++cnt;
	st.push(u),onst[u] = 1;
	for(auto x:g[u]){
		if(!low[x])			scc(x),low[u] = min(low[u],low[x]);
		else if(onst[x])	low[u] = min(low[u],idx[x]);
	}
	if(idx[u] == low[u]){
		++compnum;
		while(!comp[u]){
			comp[st.top()] = compnum;
			onst[st.top()] = 0;
			st.pop();
		}
	}
}
PII dp[N];
PII dfs(int u){
	if(dp[u].first!=-1)	return dp[u];
	PII maxx = {cval[u],mark[u]};
	for(auto x:ng[u]){
		PII ret = dfs(x);
		if(!ret.second)	continue;
		maxx.first = max(maxx.first,ret.first + cval[u]);
		maxx.second|=ret.second;
	}
	return dp[u] = maxx;
}
void solve(){
	int n,m,u,v;
	cin >> n >> m;
	while(m--){
		cin >> u >> v;
		g[u].push_back(v);
	}
	for(int i=1;i<=n;i++)
		cin >> val[i];
	int st;
	cin >> st >> u;
	while(u--){
		cin >> v;
		rest.push_back(v);
	}
	scc(st);
	for(int i=1;i<=n;i++){
		cval[comp[i]]+=val[i];
		for(auto x:g[i]){
			if(comp[x] == comp[i])	continue;
			ng[comp[i]].push_back(comp[x]);
		}
	}
	for(auto x:rest)
		mark[comp[x]] = 1;
	for(int i=1;i<=compnum;i++){
		sort(all(ng[i])),ng[i].resize(unique(all(ng[i]))-ng[i].begin());
		dp[i] = {-1,0};
	}
	cout << dfs(comp[st]).first << '\n';
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