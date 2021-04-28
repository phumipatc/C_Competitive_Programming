/*
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Algo	: LCA
	Status	: Finished
*/
#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define allst(x,y) (x).begin()+y,(x).end()
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
LL minN(vector<LL > a){
	LL minn = 1e18;
	for(auto x:a)
		minn = min(minn,x);
	return minn;
}
LL maxN(vector<LL > a){
	LL maxx = -1e18;
	for(auto x:a)
		maxx = max(maxx,x);
	return maxx;
}
LL modN(LL a,LL b,LL c = MOD){
	if(b == 0)	return 1;
	if(b == 1)	return a%c;
	LL now = modN(a,b/2);
	if(b&1)	return (((now*now)%c)*(a%c))%c;
	else	return (now*now)%c;
}
vector<PII > g[100010];
PII LCA[100010][20];
int lv[100010];
void dfs(int u,int p = 0,int state = 1,int w = 0){
	lv[u] = state;
	LCA[u][0] = {p,w};
	for(int i=1;i<=18;i++){
		LCA[u][i] = LCA[LCA[u][i-1].first][i-1];
		LCA[u][i].second = max(LCA[u][i].second,LCA[u][i-1].second);
	}
	for(auto x:g[u]){
		if(x.first == p)	continue;
		dfs(x.first,u,state+1,x.second);
	}

	// printf("%d\n",u);
	// for(int i=0;i<=18;i++)
	// 	printf("%d ",LCA[u][i].first);
	// printf("\n");
}
struct A{
	int u,v,w,id;
	bool operator < (const A&o) const{
		return w<o.w;
	}
};
set<A > sett;
set<A >::iterator now,idx;
vector<PII > ans;
void solve(){
	int n,m,u,v,w,id;
	cin >> n >> m;
	for(int i=1;i<=m;i++){
		cin >> u >> v >> w;
		if(i<n){
			g[u].push_back({v,w});
			g[v].push_back({u,w});
		}else{
			sett.insert({u,v,w,i});
		}
		if(i == n-1)	dfs(1);
	}
	while(!sett.empty()){
		now = sett.begin();
		u = now->u,v = now->v,w = now->w,id = now->id;
		sett.erase(now);
		ans.push_back({id,w});
		if(lv[u]<lv[v])	swap(u,v);
		int maxx = 0;
		for(int i=18;i>=0;i--){
			if(lv[LCA[u][i].first]<lv[v])	continue;
			maxx = max(maxx,LCA[u][i].second);
			u = LCA[u][i].first;
		}
		// printf("%d %d:%d\n",u,v,maxx);
		for(int i=18;i>=0;i--){
			if(LCA[u][i] == LCA[v][i])	continue;
			maxx = maxN({maxx,LCA[u][i].second,LCA[v][i].second});
			u = LCA[u][i].first,v = LCA[v][i].first;
		}
		if(u != v)	maxx = maxN({maxx,LCA[u][0].second,LCA[v][0].second});
		// printf("%d %d:%d\n",u,v,maxx);
		if(maxx<w)	continue;
		idx = sett.lower_bound({0,0,maxx});
		if(idx == sett.end()){
			cout << "0\n";
			exit(0);
		}else{
			ans.back().second = idx->w;
			sett.insert({idx->u,idx->v,w,idx->id});
			sett.erase(idx);
		}
	}
	sort(all(ans));
	cout << "1\n";
	for(auto x:ans)
		cout << x.second << '\n';
}
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int q = 1;
	// cin >> q;
	for(int Q=1;Q<=q;Q++){
		// cout << "Case #" << Q << ": ";
		solve();
	}
	return 0;
}