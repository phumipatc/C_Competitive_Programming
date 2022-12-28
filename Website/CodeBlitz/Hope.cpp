/*
	Task	: Hope
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 23 December 2022 [23:05]
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
const int N = 1e3+10;
struct A{
	int v;
	LL w;
	int st;
	bool operator < (const A&o) const{
		if(w != o.w)	return w>o.w;
		else			return st<o.st;
	}
};
A now;
priority_queue<A > heap;
LL treeVal[N];
vector<PII > g[N];
LL dis[N][2];
LL ans = 1;
void init(){
	
}
void dfs(int u,int p,LL sum=0){
	if(g[u].size() == 1 && g[u][0].first == p){
		// leaf
		ans = ans*((2*sum)%MOD);
		ans%=MOD;
		return ;
	}
	for(auto x:g[u]){
		if(x.first == p)	continue;
		dfs(x.first,u,(sum+x.second)%MOD);
	}
}
void solve(){
	int C;
	cin >> C;
	rep(c,1,C){
		int n,m;
		cin >> n >> m;
		rep(i,1,n)	dis[i][0] = dis[i][1] = 1e9,g[i].clear();
		while(m--){
			int u,v,w;
			cin >> u >> v >> w;
			g[u].push_back({v,w});
			g[v].push_back({u,w});
		}
		dis[1][0] = 0;
		heap.push({1,0,0});
		while(!heap.empty()){
			now = heap.top();
			heap.pop();
			if(now.v == 1 && now.st == 1){
				treeVal[c] = now.w%MOD;
				while(!heap.empty())	heap.pop();
				break;
			}
			for(auto x:g[now.v]){
				int nS = (x.first == n?1:now.st);
				if(dis[x.first][nS] <= now.w+x.second)	continue;
				dis[x.first][nS] = now.w+x.second;
				heap.push({x.first,dis[x.first][nS],nS});
			}
		}
	}
	int root;
	cin >> root;
	rep(i,1,C)	g[i].clear();
	rep(i,1,C-1){
		int u,v,w;
		cin >> u >> v >> w;
		g[u].push_back({v,(((treeVal[u]*treeVal[v])%MOD)+w)%MOD});
		g[v].push_back({u,(((treeVal[u]*treeVal[v])%MOD)+w)%MOD});
	}
	ans = 1;
	dfs(root,0);
	cout << ans << '\n';
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