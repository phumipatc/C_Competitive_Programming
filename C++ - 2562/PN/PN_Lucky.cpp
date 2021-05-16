/*
	Task	: PN_Lucky
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 13 May 2021 [19:59]
	Algo	: Dijkstra K-state
	Status	: 90 pt [WA First Case]
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
const int N = 50010;
struct A{
	int v,w,state;
	bool operator < (const A&o) const{
		if(w!=o.w)	return w>o.w;
		else		return state<o.state;
	}
};
vector<PII > g[N];
int dis[N][32],val[N];
void solve(){
	int n,m,l,st,en;
	cin >> n >> m >> l >> st >> en;
	rep(i,1,n+1)	cin >> val[i];
	while(m--){
		int u,v,w;
		cin >> u >> v >> w;
		g[u].push_back({v,w});
	}
	rep(i,1,n+1)	rep(j,1,l+2)	dis[i][j] = 2e9;
	priority_queue<A > heap;
	dis[st][1] = 0;
	heap.push({st,0,1});
	while(!heap.empty()){
		A now = heap.top();
		heap.pop();
		if(dis[now.v][now.state]<now.w)	continue;
		// printf("%d %d %d\n",now.v,now.w,now.state);
		if(now.v == en && now.state == l+1){
			cout << now.w << '\n';
			goto reset;
		}
		for(auto x:g[now.v]){
			int nxstate = now.state + (val[x.first] == now.state && now.state!=l+1);
			if(dis[x.first][nxstate]<=now.w+x.second)	continue;
			dis[x.first][nxstate] = now.w+x.second;
			heap.push({x.first,now.w+x.second,nxstate});
		}
	}
	cout << "-1\n";
	reset:rep(i,1,n+1)	g[i].clear();
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
6 8 3
1 6
0 2 1 1 4 3
1 2 20
1 3 80
3 2 100
2 4 30
4 2 40
2 6 25
2 5 15
5 6 50
*/