/*
	Task	: Wanderer
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 07 November 2021 [15:07]
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
const int N = 1e5+5;
struct A{
	int v,cntdwn = 0;
	LL w;
	A(int v,LL w,int cntdwn):v(v),w(w),cntdwn(cntdwn){}
	bool operator < (const A& o) const{
		return w > o.w;
	}
};
vector<A > g[N];
LL dis[N][12];
void init(){
	
}
void solve(){
	int n,m,q;
	cin >> n >> m >> q;
	while(m--){
		int u,v,w;
		cin >> u >> v >> w;
		g[u].emplace_back(v,w,0);
		g[v].emplace_back(u,w,0);
	}
	fill(&dis[0][0],&dis[0][0]+sizeof(dis)/sizeof(dis[0][0]),1e18);
	dis[1][0] = 0;
	priority_queue<A > heap;
	heap.push(A(1,0,0));
	while(!heap.empty()){
		A now = heap.top();
		heap.pop();
		// printf("processing: %d %lld %d\n",now.v,now.w,now.cntdwn);
		if(now.v == n){
			cout << now.w << '\n';
			return;
		}
		for(auto x:g[now.v]){
			if(!now.cntdwn){
				// freeway
				if(dis[x.v][q-1]>now.w){
					dis[x.v][q-1] = now.w;
					heap.push(A(x.v,now.w,q-1));
				}
			}
			int nq = max(0,now.cntdwn-1);
			if(dis[x.v][nq]>now.w+x.w){
				dis[x.v][nq] = now.w+x.w;
				heap.push(A(x.v,now.w+x.w,nq));
			}
		}
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