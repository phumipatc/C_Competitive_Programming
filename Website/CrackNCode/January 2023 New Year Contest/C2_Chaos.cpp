/*
	Task	: C1_Chaos
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 01 January 2023 [11:24]
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
const int N = 100010;
int p[N];
int find(int x){
	if(p[x] == x)	return x;
	return p[x] = find(p[x]);
}
void init(){
	
}
void solve(){
	int n,m;
	cin >> n >> m;
	vector<PII > edges(m);
	for(auto &x:edges)
		cin >> x.first >> x.second;
	vector<int > seq(m);
	for(auto &x:seq)
		cin >> x;
	reverse(all(seq));
	iota(p+1,p+n+1,1);
	int now = n;
	vector<int > ans;
	for(auto x:seq){
		ans.push_back(now);
		int u = edges[x-1].first,v = edges[x-1].second;
		u = find(u),v = find(v);
		if(u != v){
			p[u] = v;
			now--;
		}
	}
	reverse(all(ans));
	for(auto x:ans)
		cout << x << '\n';
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