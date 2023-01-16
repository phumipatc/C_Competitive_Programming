/*
	Task	: Cover
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 29 May 2022 [20:19]
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
const int N = 1e5+10;
struct A{
	int v,w;
	bool operator < (const A&o) const{
		return w < o.w;
	}
};
int mark[N],ans[N];
vector<int > g[N];
void init(){
	
}
void solve(){
	int n,m,p,a,b;
	cin >> n >> m >> p >> a >> b;
	rep(i,1,m){
		int u,v;
		cin >> u >> v;
		g[u].emplace_back(v);
		g[v].emplace_back(u);
	}

	priority_queue<A> heap;

	queue<A > que;
	que.push({a,0});
	fill(mark,mark+N,0);
	mark[a] = 1;
	while(!que.empty()){
		A now = que.front();
		que.pop();
		heap.push(now);
		for(auto x:g[now.v]){
			if(mark[x])	continue;
			que.push({x,now.w+1});
			mark[x] = 1;
		}
	}

	int mx = heap.top().w;

	que.push({b,0});
	fill(mark,mark+N,0);
	mark[b] = 1;
	rep(i,0,n-1){
		while(!heap.empty() && mark[heap.top().v])	heap.pop();

		ans[i] = (heap.empty()?0:heap.top().w);

		while(!que.empty()){
			A now = que.front();
			if(now.w > i)	break;
			que.pop();
			for(auto x:g[now.v]){
				if(mark[x])	continue;
				que.push({x,now.w+1});
				mark[x] = 1;
			}
		}
	}
	rep(i,1,p){
		int temp;
		cin >> temp;
		if(a == b)	cout << (temp<mx?mx:0) << '\n';
		else		cout << ans[temp] << '\n';
	}
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