/*
	Task	: Jump_Land
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Created	: 09 May 2021 [15:42]
	Algo	:
	Status	:
*/
#include<bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x),end(x)
#define allst(x,y) (x).begin()+y,(x).end()
#define remdup(x) (x).resize(unique((x).begin(),(x).end())-(x).begin())
#define sz(x) (int)(x).size()
#define decp(x) fixed << setprecision(x)
#define MOD (LL )(1e9+7)
using namespace std;
using LL = long long;
using PII = pair<int ,int >;
using PLL = pair<long long ,long long >;
const int dir4[2][4] = {{1,-1,0,0},{0,0,1,-1}};
const int dir8[2][8] = {{-1,-1,-1,0,1,1,1,0},{-1,0,1,1,-1,0,1,-1}};
const int MAX_INT = 2e9;
const LL MAX_LL = 1e18;
LL modN(LL a,LL b,LL c = MOD){
	if(b == 0)	return 1;
	if(b == 1)	return a%c;
	LL now = modN(a,b/2,c);
	if(b&1)	return (((now*now)%c)*(a%c))%c;
	else	return (now*now)%c;
}
const int N = 710;
struct A{
	int u,v;
	double w;
	bool operator < (const A&o) const{
		return w<o.w;
	}
};
int h[N*N],sp[N*N];
int p[N*N],cnt[N*N];
vector<A > t;
int n,ans = 1;
int id(int i,int j){
	return (i*n) + j;
}
int fr(int u){
	return ((u == p[u])?u:fr(p[u]));
}
void merge(int u,int v){
	if(sp[u] != sp[v]){
		double now = (double )(h[v]-h[u])/(sp[u]-sp[v]);
		if(now<0)	return ;
		t.push_back({u,v,now});
	}else if(h[u] == h[v]){
		int ru = fr(u),rv = fr(v);
		if(ru == rv)	return ;
		ans = max(ans,cnt[ru]+cnt[rv]);
		if(cnt[ru]>=cnt[rv])	cnt[ru]+=cnt[rv],p[rv] = ru;
		else					cnt[rv]+=cnt[ru],p[ru] = rv;
	}
}
vector<A > temp;
void reset(){
	reverse(all(temp));
	for(auto x:temp){
		cnt[x.u]-=cnt[x.v];
		p[x.v] = x.v;
	}
	temp.clear();
}
void solve(){
	cin >> n;
	rep(i,0,n*n)	cin >> h[i];
	rep(i,0,n*n)	cin >> sp[i];
	iota(p,p+(n*n),0);
	fill(cnt,cnt+(n*n),1);
	t.push_back({0,0,-1});
	rep(i,0,n){
		rep(j,0,n){
			if(i+1<n)	merge(id(i,j),id(i+1,j));
			if(j+1<n)	merge(id(i,j),id(i,j+1));
		}
	}
	sort(all(t));
	for(int i=1;i<t.size();i++){
		if(t[i].w!=t[i-1].w)	reset();
		int ru = fr(t[i].u),rv = fr(t[i].v);
		if(ru == rv)	continue;
		// printf("%lf\n",t[i].w);
		// for(int i=0;i<n*n;i++)
		// 	printf("%d ",fr(i));
		// printf("\n");
		ans = max(ans,cnt[ru]+cnt[rv]);
		if(cnt[ru]>=cnt[rv])	cnt[ru]+=cnt[rv],p[rv] = ru,temp.push_back({ru,rv,0});
		else					cnt[rv]+=cnt[ru],p[ru] = rv,temp.push_back({rv,ru,0});
	}
	cout << ans << '\n';
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int q = 1;
	// cin >> q;
	for(int Q=1;Q<=q;Q++){
		// cout << "Case #" << Q << ": ";
		solve();
	}
	return 0;
}