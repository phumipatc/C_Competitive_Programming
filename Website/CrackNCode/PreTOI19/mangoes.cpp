/*
	Task	: mangoes
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 15 May 2023 [20:28]
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
const int N = 5001;
struct A{
	int i,j,w;
};
int table[N][N];
vector<A > trees;
int R,C;
int calc(int i,int j,int d){
	PII upLeft = {max(1,i-d),max(1,j-d)};
	PII downRight = {min(R,i+d),min(C,j+d)};
	return table[downRight.first][downRight.second] - table[downRight.first][upLeft.second-1] - table[upLeft.first-1][downRight.second] + table[upLeft.first-1][upLeft.second-1];
}
void init(){
	
}
void solve(){
	int n,m;
	cin >> n >> m >> R >> C;
	trees.resize(n);
	for(auto &x:trees)
		cin >> x.i >> x.j >> x.w;
	rep(i,1,m){
		int u,v;
		cin >> u >> v;
		table[u][v]++;
	}
	for(int i=1;i<=R;i++)
		for(int j=1;j<=C;j++)
			table[i][j]+=table[i-1][j]+table[i][j-1]-table[i-1][j-1];
	int l = 1,r = max(R,C);
	while(l<r){
		int mid = (l+r)/2;
		bool able = true;
		for(auto x:trees){
			if(calc(x.i,x.j,mid) < x.w){
				able = false;
				break;
			}
		}
		if(able)	r = mid;
		else		l = mid+1;
	}
	cout << l << '\n';
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