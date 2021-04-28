/*
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Algo	: BFS
	Status	: 2X in evaluator
*/
#include<bits/stdc++.h>
#define all(x) begin(x),end(x)
#define allst(x,y) (x).begin()+y,(x).end()
#define sz(x) (int)(x).size()
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
		return w<o.w;
	}
};
A now;
vector<int > g[100010],rg[100010];
vector<PII > ques;
priority_queue<A > heap;
int closed[100010];
int dis1[100010],disn[100010];
void solve(){
	int n,m,q,u,v;
	cin >> n >> m >> q;
	while(m--){
		cin >> u >> v;
		g[u].push_back(v);
		rg[v].push_back(u);
	}
	for(int i=1;i<=n;i++)
		closed[i] = 1e9;
	for(int Q=1,opr;Q<=q;Q++){
		cin >> opr >> u;
		if(opr == 1)	closed[u] = Q;
		else			ques.push_back({u,Q});
	}
	memset(dis1,-1,sizeof dis1);
	heap.push({1,(int )1e9});
	dis1[1] = 1e9;
	while(!heap.empty()){
		now = heap.top();
		heap.pop();
		for(auto x:g[now.v]){
			if(dis1[x]>=min(now.w,closed[x]))	continue;
			dis1[x] = min(now.w,closed[x]);
			heap.push({x,dis1[x]});
		}
	}
	memset(disn,-1,sizeof disn);
	heap.push({n,(int )1e9});
	disn[n] = 1e9;
	while(!heap.empty()){
		now = heap.top();
		heap.pop();
		for(auto x:rg[now.v]){
			if(disn[x]>=min(now.w,closed[x]))	continue;
			disn[x] = min(now.w,closed[x]);
			heap.push({x,disn[x]});
		}
	}
	for(auto x:ques)
		cout << (dis1[x.first]>x.second && disn[x.first]>x.second) << '\n';
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int q = 1;
	// cin >> q;
	for(int Q=1;Q<=q;Q++){
		// cout << "Case #" << Q << ": ";
		solve();
	}
	return 0;
}