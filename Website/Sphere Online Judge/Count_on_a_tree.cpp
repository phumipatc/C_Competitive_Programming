/*
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Algo	: Persistent Segment Tree
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
struct A{
	LL v;
	A *l,*r;
};
A tree[2000010];
vector<int > g[100010];
vector<LL > c;
A *ver[100010];
LL val[100010];
int LCA[100010][20],lv[100010];
int cnt;
A* build(int l,int r){
	int now = ++cnt;
	if(l == r)	return &tree[now];
	int mid = (l+r)/2;
	tree[now] = {0,build(l,mid),build(mid+1,r)};
	return &tree[now];
}
A* upd(int l,int r,A* origin,int idx){
	int now = ++cnt;
	tree[now] = *origin;
	tree[now].v++;
	if(l == r)	return &tree[now];
	int mid = (l+r)/2;
	if(idx<=mid)	tree[now].l = upd(l,mid,origin->l,idx);
	else			tree[now].r = upd(mid+1,r,origin->r,idx);
	return &tree[now];
}
void dfs(int u,int p,int state=1){
	ver[u] = upd(1,sz(c)-1,ver[p],lower_bound(all(c),val[u])-c.begin());
	LCA[u][0] = p;
	lv[u] = state;
	rep(i,1,18)
		LCA[u][i] = LCA[LCA[u][i-1]][i-1];
	for(auto x:g[u]){
		if(x == p)	continue;
		dfs(x,u,state+1);
	}
}
int qry(int l,int r,A* ll1,A* ll2,A* rr1,A* rr2,int k){
	if(l == r)	return l;
	int mid = (l+r)/2,suml = (rr1->l->v) + (rr2->l->v) - (ll1->l->v) - (ll2->l->v);
	if(k<=suml)	return qry(l,mid,ll1->l,ll2->l,rr1->l,rr2->l,k);
	else		return qry(mid+1,r,ll1->r,ll2->r,rr1->r,rr2->r,k-suml);
}
void solve(){
	int u,v,k,ru,rv;
	cin >> u >> v >> k;
	if(lv[u]<lv[v])	swap(u,v);
	ru = u,rv = v;
	for(int i=17;i>=0;i--){
		if(lv[LCA[ru][i]]<lv[rv])	continue;
		ru = LCA[ru][i];
	}
	for(int i=17;i>=0;i--){
		if(LCA[ru][i] == LCA[rv][i])	continue;
		ru = LCA[ru][i],rv = LCA[rv][i];
	}
	if(ru!=rv)	ru = LCA[ru][0],rv = LCA[rv][0];
	assert(ru == rv);
	int p = LCA[ru][0];
	cout << c[qry(1,sz(c)-1,ver[p],ver[ru],ver[u],ver[v],k)] << '\n';
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int N,q = 1,u,v;
	cin >> N >> q;
	rep(i,1,N+1)
		cin >> val[i],c.push_back(val[i]);
	c.push_back(-1e18);
	sort(all(c));	c.resize(unique(all(c))-c.begin());
	rep(i,1,N){
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	ver[0] = build(1,sz(c)-1);
	dfs(1,0);
	for(int Q=1;Q<=q;Q++){
		// cout << "Case #" << Q << ": ";
		solve();
	}
	return 0;
}