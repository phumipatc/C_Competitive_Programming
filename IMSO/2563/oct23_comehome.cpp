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
	if(b == 0)	return 1;
	if(b == 1)	return a%c;
	LL now = modN(a,b/2);
	if(b&1)	return (((now*now)%c)*(a%c))%c;
	else	return (now*now)%c;
}
struct A{
	int v,w;
	bool operator < (const A&o) const{
		return w>o.w;
	}
};
priority_queue<A > heap;
vector<PII > g[150];
int dis[150];
void solve(){
	int n,u,v,w;
	char a,b;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a >> b >> w;
		g[a].push_back({b,w});
		g[b].push_back({a,w});
	}
	for(int i=1;i<=140;i++)
		dis[i] = 1e9;
	dis['Z'] = 0;
	heap.push({'Z',0});
	while(!heap.empty()){
		A now = heap.top();
		heap.pop();
		if(now.v>='A' && now.v<='Y'){
			cout << (char )now.v << ' ' << now.w << '\n';
			break;
		}
		for(auto x:g[now.v]){
			if(dis[x.first]<=now.w+x.second)	continue;
			dis[x.first] = now.w+x.second;
			heap.push({x.first,dis[x.first]});
		}
	}
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