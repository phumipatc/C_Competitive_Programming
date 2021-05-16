/*
	Task	: PZ_Follower
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 15 May 2021 [09:15]
	Algo	: BFS
	Status	: Untest
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
const int N = 110;
const int M = 1030;
int dis[N][M];
vector<PII > g[N];
void solve(){
	int n,m,st,en;
	queue<PII > que;
	cin >> n >> m >> st >> en;
	while(m--){
		int u,v,w;
		cin >> u >> v >> w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	memset(dis,0,sizeof dis);
	dis[st][0] = 1;
	que.push({st,0});
	int minn = 1e9;
	while(!que.empty()){
		PII now = que.front();
		que.pop();
		if(now.first == en)	minn = min(minn,now.second);
		for(auto x:g[now.first]){
			int nx = now.second^x.second;
			if(dis[x.first][nx])	continue;
			dis[x.first][nx] = 1;
			que.push({x.first,nx});
		}
	}
	cout << minn << '\n';
	rep(i,1,n+1)	g[i].clear();
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