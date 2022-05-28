/*
	Task	: Chocolatier
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 31 December 2021 [19:53]
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
struct A{
	int x,y,v;
	bool operator < (const A&o) const{
		return x<o.x;
	}
};
A a[N];
int dp[2][N];
void init(){
	
}
void solve(){
	int m,n,p,mx = 0;
	cin >> m >> n >> p;
	rep(i,1,p)
		cin >> a[i].x >> a[i].y >> a[i].v;
	sort(a+1,a+p+1);
	a[0].x = 1;
	deque<PII > deq;
	rep(k,1,p){
		int idx = 1;
		deq.clear();
		rep(i,1,a[k].x - a[k-1].x){
			while(!deq.empty() && deq.back().first<dp[(k+1)%2][i])	deq.pop_back();
			deq.push_back({dp[(k+1)%2][i],i});
		}
		rep(i,1,n){
			while(!deq.empty() && deq.back().first<dp[(k+1)%2][i + a[k].x - a[k-1].x])	deq.pop_back();
			deq.push_back({dp[(k+1)%2][i + a[k].x - a[k-1].x],i + a[k].x - a[k-1].x});
			while(!deq.empty() && deq.front().second < i - (a[k].x - a[k-1].x))	deq.pop_front();
			dp[k%2][i] = deq.front().first;
			if(a[k].y == i)	dp[k%2][i]+=a[k].v;
			mx = max(mx,dp[k%2][i]);
		}
	}
	cout << mx << '\n';
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