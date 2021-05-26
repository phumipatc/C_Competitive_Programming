/*
	Task	: 342E_Xenia_and_Tree
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 24 May 2021 [19:06]
	Algo	: 
	Status	: 
*/
#include<bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i <= (b); ++i)
#define repr(i, a, b) for(int i = a; i >= (b); --i)
#define all(x) begin(x),end(x)
#define allst(x,y) (x).begin()+y,(x).end()
#define rmdup(x) (x).resize(unique((x).begin(),(x).end())-(x).begin())
#define sz(x) (int)(x).size()
#define decp(x) fixed << setprecision(x)
#define MOD (LL )(1e9+7)
using namespace std;
using LL = long long;
using PII = pair<int ,int >;
using PLL = pair<long long ,long long >;
const int dir4[2][4] = {{1,-1,0,0},{0,0,1,-1}};
const int dir8[2][8] = {{-1,-1,-1,0,1,1,1,0},{-1,0,1,1,-1,0,1,-1}};
LL modN(LL a,LL b,LL c = MOD){
	if(b == 0)	return 1;
	if(b == 1)	return a%c;
	LL now = modN(a,b/2,c);
	if(b&1)	return (((now*now)%c)*(a%c))%c;
	else	return (now*now)%c;
}
const int N = 1e5+10;
vector<int > g[N];
int p[N],vis[N],sz[N];
int LCA[N][20],lv[N];
int dp[N];
void init_LCA(int u,int pa,int lvl){
	LCA[u][0] = pa;
	lv[u] = lvl;
	rep(i,1,18)
		LCA[u][i] = LCA[LCA[u][i-1]][i-1];
	for(auto x:g[u]){
		if(x == pa)	continue;
		init_LCA(x,u,lvl+1);
	}
}
int find_size(int u,int pa = 0){
	if(vis[u])	return 0;
	sz[u] = 1;
	for(auto x:g[u]){
		if(x == pa)	continue;
		sz[u]+=find_size(x,u);
	}
	return sz[u];
}
int find_centroid(int u,int pa,int n){
	for(auto x:g[u]){
		if(x == pa)		continue;
		if(vis[x])		continue;
		if(sz[x]<=n/2)	continue;
		return find_centroid(x,u,n);
	}
	return u;
}
int init_centroid(int u,int pa){
	find_size(u);
	int c = find_centroid(u,pa,sz[u]);
	vis[c] = 1;
	p[c] = pa;
	for(auto x:g[c]){
		if(vis[x])	continue;
		init_centroid(x,c);
	}
}
int find_LCA(int u,int v){
	if(lv[u]<lv[v])	swap(u,v);
	repr(i,18,0){
		if(lv[LCA[u][i]]<lv[v])	continue;
		u = LCA[u][i];
	}
	if(u == v)	return u;
	repr(i,18,0){
		if(LCA[u][i] == LCA[v][i])	continue;
		u = LCA[u][i],v = LCA[v][i];
	}
	return LCA[u][0];
}
int find_dis(int u,int v){
	int pa = find_LCA(u,v);
	return lv[u]+lv[v]-(2*lv[pa]);
}
void upd(int u,int v){
	dp[u] = min(dp[u],find_dis(u,v));
	if(p[u])	upd(p[u],v);
}
int read(int u,int v,int mn = 1e9){
	while(u){
		mn = min(mn,dp[u]+find_dis(u,v));
		u = p[u];
	}
	return mn;
}
void solve(){
	int n,m,u,v;
	cin >> n >> m;
	rep(i,1,n-1){
		cin >> u >> v;
		g[u].push_back(v),g[v].push_back(u);
	}
	init_LCA(1,0,1);
	init_centroid(1,0);
	fill(dp,dp+N,1e9);
	upd(1,1);
	int opr;
	while(m--){
		cin >> opr >> u;
		if(opr == 1){
			upd(u,u);
		}else{
			// printf("reading %d\n",u);
			cout << read(u,u) << '\n';
		}
	}
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
10 3
10 7
10 6
1 4
7 8
5 1
6 2
7 5
6 3
7 9
2 9
2 8
2 2

*/