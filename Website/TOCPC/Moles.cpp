/*
	Task	: Moles
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 21 November 2021 [21:25]
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
const int N = 1e6+5;
struct A{
	int s,t,sub,sum;
	bool operator < (const A&o) const{
		if(sum!=o.sum)	return sum<o.sum;
		else			return t<o.t;
	}
};
A a[N];
int LIS[N];
void init(){
	
}
void solve(){
	int n,st;
	cin >> n >> st;
	rep(i,1,n){
		cin >> a[i].s >> a[i].t;
		a[i].sub = a[i].t - a[i].s;
		a[i].sum = a[i].t + a[i].s;
	}
	sort(a+1,a+n+1);
	int cnt = 0;
	rep(i,1,n){
		if(st > a[i].sum || -st > a[i].sub)	continue;
		int idx = upper_bound(LIS,LIS+cnt,a[i].sub) - LIS;
		if(idx == cnt)	cnt++;
		LIS[idx] = a[i].sub;
	}
	cout << cnt << '\n';
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