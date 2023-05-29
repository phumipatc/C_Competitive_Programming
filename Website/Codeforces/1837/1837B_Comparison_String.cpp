/*
	Task	: 1837B_Comparison_String
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 25 May 2023 [21:46]
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
const int N = 110;
char str[N];
int deg[N],dis[N];
vector<int > g[N];
void init(){
	
}
void solve(){
	int n;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> str[i];
		if(str[i] == '<'){
			// a[i] < a[i+1]
			g[i].push_back(i+1);
			deg[i+1]++;
		}else{
			g[i+1].push_back(i);
			deg[i]++;
		}
	}
	queue<int > que;
	for(int i=1;i<=n+1;i++){
		if(deg[i])	continue;
		que.push(i);
		dis[i] = 1;
	}
	int mx = 0;
	while(!que.empty()){
		int now = que.front();
		que.pop();
		mx = max(mx,dis[now]);
		for(auto x:g[now]){
			deg[x]--;
			if(deg[x] > 0)	continue;
			dis[x] = dis[now]+1;
			que.push(x);
		}
	}
	cout << mx << '\n';
	for(int i=1;i<=n+1;i++)
		g[i].clear();
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	// freopen("d:/Code/C_Programming/input.in","r",stdin);
	init();
	int q = 1;
	cin >> q;
	for(int Q=1;Q<=q;Q++){
		// cout << "Case #" << Q << ": ";
		solve();
	}
	return 0;
}