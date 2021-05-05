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
	int v,w,k;
	bool operator < (const A&o) const{
		return w>o.w;
	}
};
priority_queue<A > heap;
vector<PII > g[100010];
int dis[100010][7];
int cal(int n,int v){
	return (v < -100)?n+1:n;
}
void solve(){
	int n,m,k,u,v,w;
	cin >> n >> m >> k;
	while(m--){
		cin >> u >> v >> w;
		g[u].push_back({v,w});
	}
	for(int i=1;i<=n;i++)
		for(int j=0;j<=k;j++)
			dis[i][j] = 1e9;
	dis[1][0] = 0;
	heap.push({1,0,0});
	while(!heap.empty()){
		A now = heap.top();
		heap.pop();
		if(now.v == n){
			cout << now.w;
			return ;
		}
		for(auto x:g[now.v]){
			if(cal(now.k,x.second)>k)										continue;
			if(dis[x.first][cal(now.k,x.second)]<=now.w+max(0,x.second))	continue;
			dis[x.first][cal(now.k,x.second)] = now.w+max(0,x.second);
			heap.push({x.first,now.w+max(0,x.second),cal(now.k,x.second)});
		}
	}
	cout << "-1\n";
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