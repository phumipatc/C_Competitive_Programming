/*
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Algo	: Dijkstra k-state
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
struct A{
	int v;
	LL w;
	int l,p;
	bool operator < (const A&o) const{
		return w>o.w;
	}
};
A now;
vector<A > g[80010];
priority_queue<A > heap;
int mark[80010];
int sp[10] = {1,2,4,8,16,32,64,128,256};
LL dis[80010][12];
void solve(){
	int n,m,l,q,u,v,w;
	cin >> n >> m >> l >> q;
	while(m--){
		cin >> u >> v >> w;
		g[u].push_back({v,w});
	}
	for(int i=1;i<=l;i++){
		cin >> u;
		mark[u] = 1;
	}
	for(int i=1;i<=n;i++)
		for(int j=0;j<=q;j++)
			dis[i][j] = 1e18;
	dis[1][0] = 0;
	heap.push({1,0,0,0});
	while(!heap.empty()){
		now = heap.top();
		heap.pop();
		if(now.v == n){
			cout << now.w << '\n';
			break;
		}
		if(mark[now.v] && now.l!=now.v && now.p<q){
			for(auto x:g[now.v]){
				if(dis[x.v][now.p+1]<=now.w+(x.w/sp[now.p+1]))	continue;
				dis[x.v][now.p+1] = now.w+(x.w/sp[now.p+1]);
				heap.push({x.v,dis[x.v][now.p+1],now.v,now.p+1});
			}
		}
		for(auto x:g[now.v]){
			if(dis[x.v][now.p]<=now.w+(x.w/sp[now.p]))	continue;
			dis[x.v][now.p] = now.w+(x.w/sp[now.p]);
			heap.push({x.v,dis[x.v][now.p],now.l,now.p});
		}
	}
}
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int q = 1;
	// cin >> q;
	while(q--){
		solve();
	}
	return 0;
}