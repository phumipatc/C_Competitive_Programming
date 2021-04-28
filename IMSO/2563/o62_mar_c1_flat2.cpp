/*
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Algo	: Sack
	Status	: Finished
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
vector<int > pos[1000010];
int a[100010];
int p[100010],sz[100010];
int ans[100010];
int fr(int u){
	return p[u] = ((p[u] == u)?u:fr(p[u]));
}
void solve(){
	int n,w,ru,rv;
	cin >> n >> w;
	memset(ans,-1,sizeof ans);
	fill(sz+1,sz+n+1,1);
	iota(p+1,p+n+1,1);
	for(int i=1;i<=n;i++){
		cin >> a[i];
		pos[a[i]].push_back(i);
	}
	for(int i=1000000;i>=1;i--){
		for(auto x:pos[i]){
			if(x!=1 and a[x-1]>=a[x]){
				ru = fr(x),rv = fr(x-1);
				if(ru!=rv)	p[ru] = rv,sz[rv]+=sz[ru];
			}
			if(x!=n and a[x+1]>=a[x]){
				ru = fr(x),rv =fr(x+1);
				if(ru!=rv)	p[ru] = rv,sz[rv]+=sz[ru];
			}
		}
		for(auto x:pos[i]){
			int h = sz[fr(x)]-1;
			ans[h] = max(ans[h],i);
		}
	}
	if(w == -10){
		for(int i=1;i<=n;i++)
			cout << ans[i] << ' ';
	}else
		cout << ans[w] << '\n';
}
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int q = 1;
	// cin >> q;
	for(int Q=1;Q<=q;Q++){
		// cout << "Case #" << Q << ": ";
		solve();
	}
	return 0;
}