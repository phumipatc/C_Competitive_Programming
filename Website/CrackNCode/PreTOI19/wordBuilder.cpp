/*
	Task	: wordBuilder
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 15 May 2023 [19:13]
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
const int N = 200010;
char c[N];
int dis[N];
vector<int > minDis[30];
vector<int > g[N];
void init(){
	
}
void solve(){
	int n,m,k;
	cin >> n >> m >> k >> c+1;
	while(m--){
		int u,v;
		cin >> u >> v;
		g[u].emplace_back(v);
		g[v].emplace_back(u);
	}
	queue<int > que;
	for(int i=2;i<=n;i++)
		dis[i] = 1e9;
	dis[1] = 0;
	que.push(1);
	while(!que.empty()){
		int now = que.front();
		que.pop();
		for(auto x:g[now]){
			if(dis[x] != 1e9)	continue;
			dis[x] = dis[now]+1;
			que.push(x);
		}
	}
	for(int i=1;i<=n;i++)
		minDis[c[i]-'A'].push_back(-dis[i]*2);
	for(int i=0;i<26;i++)
		sort(all(minDis[i]));
	cin >> c+1;
	LL ans = 0;
	for(int i=1;i<=k;i++){
		if(minDis[c[i]-'A'].empty()){
			cout << "-1\n";
			return ;
		}
		ans-=minDis[c[i]-'A'].back();
		minDis[c[i]-'A'].pop_back();
	}
	cout << ans << '\n';
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