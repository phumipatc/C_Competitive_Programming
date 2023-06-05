/*
	Task	: TOI19_Phitsanulok
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 05 June 2023 [10:07]
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
const int N = 80010;
const int STATE = (1<<19)+10;
struct A{
	int state;
	int weight;
	bool operator < (const A&o) const{
		return weight > o.weight;
	}
};
vector<A > g[STATE];
int dis[STATE];
int poisonState[N];
void init(){
	
}
void solve(){
	int n,s,w;
	cin >> n >> s;
	rep(i,1,n){
		cin >> w;
		int antidote = 0, poison = 0;
		rep(i,0,s-1){
			int num;
			cin >> num;
			if(num == 1){
				antidote|=(1<<i);
			}else if(num == -1){
				poison|=(1<<i);
			}
		}
		g[poison].push_back({antidote,w});
		poisonState[i] = poison;
	}
	rep(i,0,(1<<s)-1){
		dis[i] = 1e9;
		rep(j,0,s-1)
			if((i&(1<<j)) == 0)
				g[i|(1<<j)].push_back({i,0});
	}
	priority_queue<A > heap;
	dis[0] = 0;
	heap.push({0,0});
	while(!heap.empty()){
		A now = heap.top();
		heap.pop();
		for(auto x:g[now.state]){
			if(dis[x.state] <= now.weight + x.weight)	continue;
			dis[x.state] = now.weight + x.weight;
			heap.push({x.state,dis[x.state]});
		}
	}
	int mx = 0;
	rep(i,1,n)
		mx = max(mx,(dis[poisonState[i]] == 1e9?0:dis[poisonState[i]]));
	cout << mx << '\n';
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