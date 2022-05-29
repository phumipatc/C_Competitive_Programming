/*
	Task	: Multiverse
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 29 May 2022 [09:21]
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
const int N = 1e5;
int a[N+10],p[N+10],sum[N+10];
int fr(int u){
	if(p[u] == u)	return u;
	else			return p[u] = fr(p[u]);
}
void init(){
	
}
void solve(){
	int n,ans = 1;
	cin >> n;
	rep(i,1,n)
		cin >> a[i];
	iota(p,p+n+1,0);
	fill(sum,sum+n+1,0);
	rep(i,1,n){
		int u = fr(i),v = fr(a[i]);
		if(u == v)	continue;
		p[u] = v;
	}
	rep(i,1,n){
		int u = fr(i);
		sum[u]++;
	}
	rep(i,1,n){
		if(sum[i] <= 1)	continue;
		if(sum[i]%2 == 0)	ans = max(ans,2);
		else				ans = max(ans,3);
	}
	cout << ans << '\n';
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