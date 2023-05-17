/*
	Task	: Long_Jump
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 20 November 2021 [19:45]
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
vector<int > g[N];
int cnt1[N],cnt2[N];
struct A{
	int u,last;
	string st;
};
void init(){
	
}
void solve(){
	int n,st,en,u,v;
	string val;
	cin >> n >> st >> en;
	rep(i,1,n-1){
		cin >> u >> v;
		g[u].emplace_back(v);
		g[v].emplace_back(u);
	}
	cin >> val;
	val.insert(val.begin(),'0');

	fill(cnt1,cnt1+N,-1);
	fill(cnt2,cnt2+N,-1);
	queue<A > que;
	que.push({st,0,string()});
	while(!que.empty()){
		A now = que.front();
		que.pop();
		if(now.st.empty()){
			if(val[now.u] == '(')	now.st.append("(");
			else					continue;
		}else{
			if(val[now.u] == ')')	now.st.pop_back();
			else					now.st.append("(");
		}
		cnt1[now.u] = now.st.size();
		for(auto x:g[now.u]){
			if(x == now.last)	continue;
			que.push({x,now.u,now.st});
		}
	}

	que.push({en,0,string()});
	while(!que.empty()){
		A now = que.front();
		que.pop();
		if(now.st.empty()){
			if(val[now.u] == ')')	now.st.append(")");
			else					continue;
		}else{
			if(val[now.u] == '(')	now.st.pop_back();
			else					now.st.append(")");
		}
		cnt2[now.u] = now.st.size();
		for(auto x:g[now.u]){
			if(x == now.last)	continue;
			que.push({x,now.u,now.st});
		}
	}
	map<int ,int > mapp;
	rep(i,1,n)
		mapp[cnt2[i]]++;
	LL ans = 0;
	rep(i,1,n){
		if(cnt1[i] == -1)	continue;
		ans+=mapp[cnt1[i]];
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