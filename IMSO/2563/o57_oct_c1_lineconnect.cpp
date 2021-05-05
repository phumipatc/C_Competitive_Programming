/*
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Algo	: MST, BS
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
int pos[100010];
int p[100010];
int fr(int u){
	return (u == p[u])?u:p[u] = fr(p[u]);
}
vector<int > a,b;
void solve(){
	int n,u,v,ru,rv;
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> pos[i],p[i] = i;
	for(int i=1;i<=n-2;i++){
		cin >> u >> v;
		ru = fr(u),rv = fr(v);
		if(ru == rv)	continue;
		p[ru] = rv;
	}
	int minn = fr(1),idx;
	for(int i=1;i<=n;i++){
		if(fr(i) == minn)	a.push_back(pos[i]);
		else				b.push_back(pos[i]);
	}
	sort(all(a)),sort(all(b));
	minn = MAX_INT;
	for(auto x:a){
		idx = upper_bound(all(b),x)-b.begin();
		minn = minN({minn,abs(b[idx]-x),abs(x-b[max(0,idx-1)])});
		// printf("%d %d\n",abs(b[idx]-x),abs(x-b[max(0,idx-1)]));
	}
	cout << minn << '\n';
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