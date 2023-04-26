/*
	Task	: 1328E_Tree_Queries
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 04 April 2023 [12:54]
	Algo	: 
	Status	: 
*/
#include<bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i <= (b); ++i)
#define repr(i, a, b) for(int i = a; i >= (b); --i)
#define repl(i, a, b) for(LL i = a; i <= (b); ++i)
#define reprl(i, a, b) for(LL i = a; i >= (b); --i)
#define all(x) begin(x),end(x)
#define allst(x,y) (x).begin()+y,(x).end()
#define rmdup(x) sort(all(x)),(x).resize(unique((x).begin(),(x).end())-(x).begin())
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
const int N = 200010;
vector<int > g[N];
int lv[N],lca[N][20];
void dfs(int u,int p,int lvl = 1){
	lv[u] = lvl;
	lca[u][0] = p;
	rep(i,1,18)
		lca[u][i] = lca[lca[u][i-1]][i-1];
	for(auto x:g[u]){
		if(x == p)	continue;
		dfs(x,u,lvl+1);
	}
}
int findLCA(int u,int v){
	// make sure that lv[u] is not less than lv[v];
	if(lv[u] < lv[v])	swap(u,v);
	repr(i,18,0){
		if(lv[lca[u][i]] < lv[v])	continue;
		u = lca[u][i];
	}
	// now lv[u] is equal to lv[v];
	if(u == v)	return u;
	repr(i,18,0){
		if(lv[lca[u][i]] == lv[lca[v][i]])	continue;
		u = lca[u][i],v = lca[v][i];
	}
	return lca[u][0];
}
void init(){

}
void solve(){
	int n,m;
	cin >> n >> m;
	rep(i,1,n-1){
		int u,v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1,0);
	while(m--){
		int num,target,maxlv = 0;
		cin >> num;
		vector<int > v(num);
		for(auto &x:v){
			cin >> x;
			if(maxlv < lv[x]){
				maxlv = lv[x];
				target = x;
			}
		}
		for(auto &x:v){
			if(x == target || x == 1)	continue;
			x = lca[x][0];
		}
		bool yes = true;
		for(auto x:v){
			if(findLCA(x,target) != x){
				yes = false;
				break;
			}
		}
		cout << (yes?"YES\n":"NO\n");
	}
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	// freopen("d:/Code/C_Programming/input.in","r",stdin);
	init();
	int q = 1;
	// cin >> q;
	for(int Q=1;Q<=q;Q++){
		// cout << "Case #" << Q << ": ";
		solve();
	}
	return 0;
}