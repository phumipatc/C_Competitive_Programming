/*
	Task	: _PZ_Food_Tour
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 13 May 2021 [08:14]
	Algo	: DP on tree
	Status	: Finished
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
const int N = 60010;
const int M = 510;
vector<PII> g[N];
vector<int > ug[N];
int hotel[N],foodnum[N];
int cnt;
void group(int u,int p){
	foodnum[u] = cnt;
	for(auto x:ug[u]){
		if(x == p)	continue;
		group(x,u);
	}
}
struct A{
	LL h,f[M];
}now[N];
LL ans[M];
void dfs(int u,int p){
	now[u].h = (hotel[u]?0:-1e18);
	rep(i,1,cnt+1)	now[u].f[i] = -1e18;
	if(foodnum[u])	now[u].f[foodnum[u]] = 0;
	for(auto x:g[u]){
		if(x.first == p)	continue;
		dfs(x.first,u);
		rep(i,1,cnt+1){
			ans[i] = max({ans[i],now[u].h + now[x.first].f[i] + x.second,now[u].f[i] + now[x.first].h + x.second});
			now[u].f[i] = max(now[u].f[i],now[x.first].f[i] + x.second);
		}
		now[u].h = max(now[u].h,now[x.first].h + x.second);
	}
}
void solve(){
	int n,m,r,k,u,v,w;
	cin >> n >> m >> r >> k;
	rep(i,1,n){
		cin >> u >> v >> w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	rep(i,0,r){
		cin >> u >> v;
		ug[u].push_back(v);
		ug[v].push_back(u);
	}
	rep(i,0,k){
		cin >> u;
		hotel[u] = 1;
	}
	rep(i,1,n+1){
		if(!sz(ug[i]))	continue;
		if(foodnum[i])	continue;
		++cnt;
		group(i,0);
	}
	dfs(1,0);
	LL sum = 0;
	rep(i,1,cnt+1)
		sum+=ans[i];
	cout << sum*2 << '\n';
	rep(i,1,n+1)	g[i].clear(),ug[i].clear();
	memset(hotel,0,sizeof hotel);
	memset(foodnum,0,sizeof foodnum);
	memset(ans,0,sizeof ans);
	cnt = 0;
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