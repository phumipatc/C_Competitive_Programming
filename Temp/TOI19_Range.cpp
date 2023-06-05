/*
	Task	: TOI19_Range
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 31 May 2023 [09:14]
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
const int N = 400010;
struct A{
	int l,r,idx;
	bool operator < (const A&o) const{
		if(l != o.l)	return l>o.l;
		else			return r<o.r;
	}
};
vector<A > mount;
int LIS[N];
int ans[N];
void init(){
	
}
void solve(){
	int n;
	cin >> n;
	mount.resize(n);
	rep(i,0,n-1){
		cin >> mount[i].l >> mount[i].r;
		mount[i].idx = i+1;
	}
	sort(all(mount));
	int cnt = 0;
	for(auto x:mount){
		// cout << "processing " << x.l << ' ' << x.r << '\n';
		// for(int i=0;i<cnt;i++)
		// 	cout << LIS[i] << ' ';
		// cout << '\n';
		int idx = upper_bound(LIS,LIS+cnt,x.r)-LIS;
		if(idx == cnt)
			cnt++;
		ans[x.idx] = idx+1;
		LIS[idx] = x.r;
	}
	cout << *max_element(ans+1,ans+n+1) << '\n';
	rep(i,1,n)
		cout << ans[i] << ' ';
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