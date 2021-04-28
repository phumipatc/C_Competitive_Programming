/*
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Algo	:
	Status	:
*/
#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define allst(x,y) (x).begin()+y,(x).end()
#define decp(x) fixed << setprecision(x)
#define MOD (LL )(1e9+7)
using namespace std;
using LL = long long;
using PII = pair<int ,int >;
using PLL = pair<long long ,long long >;
const int dir4[2][4] = {{1,-1,0,0},{0,0,1,-1}};
const int dir8[2][8] = {{-1,-1,-1,0,1,1,1,0},{-1,0,1,1,-1,0,1,-1}};
const int MAX_INT = 1e9;
const LL MAX_LL = 1e18;
LL minN(vector<LL > a){
	LL minn = 1e18;
	for(auto x:a)
		minn = min(minn,x);
	return minn;
}
LL maxN(vector<LL > a){
	LL maxx = -1e18;
	for(auto x:a)
		maxx = max(maxx,x);
	return maxx;
}
LL modN(LL a,LL b,LL c = MOD){
	if(b == 0)	return 1;
	if(b == 1)	return a%c;
	LL now = modN(a,b/2);
	if(b&1)	return (((now*now)%c)*(a%c))%c;
	else	return (now*now)%c;
}
struct A{
	int u,v,w;
	bool operator < (const A&o) const{
		return w<o.w;
	}
};
vector<A > g;
int p[5010];
int fr(int u){
	if(u == p[u])	return u;
	else			return p[u] = fr(p[u]);
}
int ans[5010];
void solve(){
	int num;
	cin >> num;
	cout << ans[num] << '\n';
}
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int n,m,q = 1,now,u,v,w,ru,rv;
	cin >> n >> m >> q;
	now = n;
	for(int i=1;i<=n;i++)	p[i] = i;
	while(m--){
		cin >> u >> v >> w;
		g.push_back({u,v,w});
	}
	sort(all(g));
	for(auto x:g){
		ru = fr(x.u),rv = fr(x.v);
		if(ru == rv)	continue;
		p[ru] = rv;
		now--;
		ans[now] = x.w;
	}
	for(int Q=1;Q<=q;Q++){
		// cout << "Case #" << Q << ": ";
		solve();
	}
	return 0;
}