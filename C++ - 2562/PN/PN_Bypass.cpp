/*
	Task	: PN_Bypass
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 16 May 2021 [16:48]
	Algo	: 
	Status	: 
*/
#include<bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < (b); ++i)
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
const int N = 100010;
vector<int > g[N];
vector<PII > edge;
int p[N],sub[N];
PII mx[N][2];
void dfs(int u,int pa){
	sub[u] = 1;
	p[u] = pa;
	mx[u][0] = mx[u][1] = {0,0};
	for(auto x:g[u]){
		if(x == pa)	continue;
		dfs(x,u);
		sub[u]+=sub[x];
		if(sub[x]>mx[u][0].first)		mx[u][1] = mx[u][0],mx[u][0] = {sub[x],x};
		else if(sub[x]>mx[u][1].first)	mx[u][1] = {sub[x],x};
	}
}
void solve(){
	int n,u,v;
	cin >> n;
	rep(i,1,n){
		cin >> u >> v;
		g[u].emplace_back(v),g[v].emplace_back(u);
		edge.emplace_back(u,v);
	}
	dfs(1,0);
	rep(i,1,n+1){
		// printf("SUB:%d %d %d\n",i,sub[i],p[i]);
		if(n-sub[i]>mx[i][0].first)			mx[i][1] = mx[i][0],mx[i][0] = {n-sub[i],p[i]};
		else if(n-sub[i]>mx[i][1].first)	mx[i][1] = {n-sub[i],p[i]};
	}
	// rep(i,1,n+1)
	// 	printf("DB:%d %d\n",mx[i][1].first,mx[i][1].second);
	LL ans = 0;
	for(auto &x:edge){
		if(p[x.first] == x.second)
			swap(x.first,x.second);
		int l = (mx[x.first][0].second != x.second)?mx[x.first][0].first:mx[x.first][1].first;
		int r = (mx[x.second][0].second != x.first)?mx[x.second][0].first:mx[x.second][1].first;
		// printf("%d %d:%d %d\n",x.first,x.second,l,r);
		ans = max(ans,(LL )l*r);
	}
	cout << ans << '\n';
	rep(i,1,n+1)	g[i].clear();
	edge.clear();
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int q = 1;
	cin >> q;
	for(int Q=1;Q<=q;Q++){
		// cout << "Case #" << Q << ": ";
		solve();
	}
	return 0;
}
/*
1
6
1 3
2 3
3 4
4 5
5 6

*/