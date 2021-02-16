/*
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Algo	:
	Status	:
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
	if(b == 0)	return 0;
	if(b == 1)	return a%c;
	LL now = modN(a,b/2);
	if(b&1)	return (((now*now)%c)*(a%c))%c;
	else	return (now*now)%c;
}
struct A{
	int v,w,state;
	bool operator < (const A&o) const{
		return w>o.w;
	}
};
priority_queue<A > heap;
int dis[50010][32];
int a[50010];
vector<PII > g[50010];
void solve(){
	int n,m,l,st,en,u,v,w;
	cin >> n >> m >> l >> st >> en;
	for(int i=1;i<=n;i++)
		cin >> a[i],a[i] = (a[i] == l + 1?-1:a[i]);
	while(m--){
		cin >> u >> v >> w;
		g[u].push_back({v,w});
	}
	for(int i=1;i<=n;i++)
		for(int j=0;j<=l;j++)
			dis[i][j] = 1e9;
	dis[st][0] = 0;
	heap.push({st,0,0});
	while(!heap.empty()){
		auto now = heap.top();
		heap.pop();
		for(auto x:g[now.v]){
			if(a[x.first] == now.state + 1 and dis[x.first][now.state + 1]>now.w + x.second){
				dis[x.first][now.state + 1] = now.w + x.second;
				heap.push({x.first,now.w + x.second,now.state + 1});
			}else if(a[x.first] != now.state + 1 and dis[x.first][now.state]>now.w + x.second){
				dis[x.first][now.state] = now.w + x.second;
				heap.push({x.first,now.w + x.second, now.state});
			}
		}
	}
	cout << dis[en][l] << '\n';
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