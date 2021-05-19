/*
	Task	: PZ_Fair
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 17 May 2021 [23:20]
	Algo	: Dijkstra
	Status	: Finished
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
const int K = 110;
const int N = 50010;
struct A{
	int v,w;
	bool operator < (const A&o) const{
		return w>o.w;
	}
};
vector<A > g[N];
int dis[K][N],id[N];
vector<int > node[K];
void solve(){
	int n,m,a;
	cin >> n >> m >> a;
	rep(i,1,n){
		cin >> id[i];
		node[id[i]].push_back(i);
	}
	int u,v,w;
	while(m--){
		cin >> u >> v >> w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	priority_queue<A > heap;
	rep(i,1,100){
		rep(j,1,n)	dis[i][j] = 1e9;
		for(auto x:node[i])
			heap.push({x,0}),dis[i][x] = 0;
		while(!heap.empty()){
			A now = heap.top();
			heap.pop();
			if(dis[i][now.v]<now.w)	continue;
			for(auto x:g[now.v]){
				if(dis[i][x.v]<=now.w+x.w)	continue;
				dis[i][x.v] = now.w + x.w;
				heap.push({x.v,now.w + x.w});
			}
		}
	}
	LL ans = 1e18;
	rep(i,1,n){
		vector<int > temp;
		rep(j,1,100)	temp.push_back(dis[j][i]);
		sort(all(temp));
		LL sum = 0;
		rep(j,0,a-1){
			if(temp[j] == 1e9){
				sum = 1e18;
				break;
			}
			sum+=temp[j];
		}
		ans = min(ans,sum);
	}
	if(ans == 1e18)	cout << "-1\n";
	else			cout << ans << '\n';
	rep(i,1,n)		g[i].clear();
	rep(i,1,100)	node[i].clear();
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