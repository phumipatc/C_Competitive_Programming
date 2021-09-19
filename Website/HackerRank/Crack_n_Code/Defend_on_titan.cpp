/*
	Task	: Defend_on_titan
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 04 September 2021 [21:36]
	Algo	: Dijkstra
	Status	: Finished
*/
#include<bits/stdc++.h>
#define rep(i, a, b) for(LL i = a; i <= (b); ++i)
#define repr(i, a, b) for(LL i = a; i >= (b); --i)
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
const int N = 1010;
struct A{
	int i,j;
	LL v;
	bool operator < (const A&o) const{
		return v>o.v;
	}
};
LL dp[N][N];
int v[N][N];
void init(){
	
}
void solve(){
	int n,m;
	cin >> n >> m;
	rep(i,1,n)
		rep(j,1,m)
			cin >> v[i][j];
	fill(&dp[0][0],&dp[0][0] + sizeof(dp)/sizeof(dp[0][0]),1e18);
	fill(dp[0],dp[0]+N,0);
	priority_queue<A > heap;	
	rep(i,1,m)
		heap.push({0,(int )i,0});
	while(!heap.empty()){
		auto now = heap.top();
		heap.pop();
		if(now.i == n+1){
			cout << now.v << '\n';
			break;
		}
		rep(k,0,3){
			int ni = now.i+dir4[0][k],nj = now.j+dir4[1][k];
			if(ni<0 || ni>n+1 || nj<1 || nj>m)	continue;
			if(dp[ni][nj]<=now.v+v[ni][nj])		continue;
			dp[ni][nj] = now.v+v[ni][nj];
			heap.push({ni,nj,now.v+v[ni][nj]});
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