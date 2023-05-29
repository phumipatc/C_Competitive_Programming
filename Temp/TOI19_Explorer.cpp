/*
	Task	: TOI19_Explorer
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 29 May 2023 [09:25]
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
const int N = 500010;
vector<int > g[N];
LL f[N];
void init(){
	f[0] = f[1] = 1;
	f[2] = 2;
	rep(i,3,500000)
		f[i] = (f[i-1]*i)%MOD;
}
LL dfs(int u,int p=0){
	// cerr << u << ' ' << p << '\n';
	if(g[u].size() == 0 || (g[u].size() == 1 && g[u][0] == p)){
		return 1;
	}
	LL ret = 1;
	int cnt = 0;
	for(auto x:g[u]){
		if(x == p)	continue;
		cnt++;
		ret*=dfs(x,u);
		ret%=MOD;
	}
	ret = (ret*f[cnt])%MOD;
	return ret;
}
void solve(){
	int n;
	cin >> n;
	int last = 0,num;
	cin >> last;
	rep(i,2,2*n-1){
		cin >> num;
		g[last].push_back(num);
		last = num;
	}
	cout << dfs(last) << '\n';
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