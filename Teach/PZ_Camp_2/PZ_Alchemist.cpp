/*
	Task	: PZ_Alchemist
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 19 May 2021 [09:33]
	Algo	: DP on tree
	Status	: Finished
*/
#include<bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i <= (b); ++i)
#define repr(i, a, b) for(int i = a; i >= (b); --i)
#define all(x) begin(x),end(x)
#define allst(x,y) (x).begin()+y,(x).end()
#define rmdup(x) (x).resize(unique((x).begin(),(x).end())-(x).begin())
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
const int N = 10010;
vector<int > g[N];
int a[N];
map<int ,int > mapp[N];
int K,ans;
void dfs(int u,int p){
	mapp[u][(1<<a[u])] = 0;
	map<int ,int > now;
	now[(1<<a[u])] = 0;
	for(auto x:g[u]){
		if(x == p)	continue;
		dfs(x,u);
		for(auto y:mapp[u]){
			for(auto z:mapp[x]){
				// printf("%d %d %d %d %d\n",u,x,y.first,z.first,y.first|z.first);
				if(now.find(y.first|z.first) == now.end())	now[y.first|z.first] = 1e9;
				now[y.first|z.first] = min(now[y.first|z.first],y.second + z.second + 1);
			}
		}
		for(auto y:mapp[x]){
			if(mapp[u].find(y.first|(1<<a[u])) == mapp[u].end())	mapp[u][y.first|(1<<a[u])] = 1e9;
			mapp[u][y.first|(1<<a[u])] = min(mapp[u][y.first|(1<<a[u])],y.second + 1);
		}
	}
	for(auto x:now){
		// printf("%d %d %d %d\n",u,x.first,__builtin_popcount(x.first),x.second);
		if(__builtin_popcount(x.first)<K)	continue;
		ans = min(ans,x.second);
	}
}
void solve(){
	int n,u,v;
	cin >> n >> K;
	rep(i,1,n)
		cin >> a[i],a[i]--;
	rep(i,1,n-1){
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	ans = 1e9;
	dfs(1,0);
	if(ans == 1e9)	cout << "-1\n";
	else			cout << ans << '\n';
	rep(i,1,n)	g[i].clear(),mapp[i].clear();
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int q = 1;
	cin >> q;
	for(int Q=1;Q<=q;Q++){
		// cout << "Case #" << Q << ": ";
		solve();
	}
	return 0;
}