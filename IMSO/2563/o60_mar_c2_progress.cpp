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
	if(b == 0)	return 0;
	if(b == 1)	return a%c;
	LL now = modN(a,b/2);
	if(b&1)	return (((now*now)%c)*(a%c))%c;
	else	return (now*now)%c;
}
struct A{
	int v,sum,l,r;
	A operator + (const A&o) const{
		A now;
		now.v = maxN({v,o.v,r+o.l});
		now.l = max(l,sum+o.l);
		now.r = max(o.r,r+o.sum);
		now.sum = sum+o.sum;
		return now;
	}
}tree[400010];
int a[100010];
void build(int l,int r,int now){
	if(l == r){
		tree[now] = {a[l],a[l],a[l],a[l]};
		return ;
	}
	int mid = (l+r)/2;
	build(l,mid,now*2);
	build(mid+1,r,now*2+1);
	tree[now] = tree[now*2]+tree[now*2+1];
}
void upd(int l,int r,int now,int idx,int v){
	if(l == r){
		tree[now] = {v,v,v,v};
		return ;
	}
	int mid = (l+r)/2;
	if(idx<=mid)	upd(l,mid,now*2,idx,v);
	else			upd(mid+1,r,now*2+1,idx,v);
	tree[now] = tree[now*2]+tree[now*2+1];
}
void solve(){
	int n,m,u,v;
	cin >> n >> m;
	for(int i=0;i<n;i++)
		cin >> a[i];
	build(0,n-1,1);
	cout << tree[1].v << '\n';
	while(m--){
		cin >> u >> v;
		upd(0,n-1,1,u,v);
		cout << tree[1].v << '\n';
	}
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