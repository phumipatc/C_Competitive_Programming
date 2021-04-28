/*
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Algo	: Lazy Segment Tree
	Status	: Finished
*/
#include<bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x),end(x)
#define allst(x,y) (x).begin()+y,(x).end()
#define sz(x) (int)(x).size()
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
LL modN(LL a,LL b,LL c = MOD){
	if(b == 0)	return 1;
	if(b == 1)	return a%c;
	LL now = modN(a,b/2);
	if(b&1)	return (((now*now)%c)*(a%c))%c;
	else	return (now*now)%c;
}
struct A{
	int sum,val;
	A operator + (const A&o) const{
		return {sum+o.sum,val+o.val};
	}
};
int a[100010];
vector<int > c;
A tree[400010];
int lazy[400010];
void build(int l,int r,int now){
	if(l == r){
		tree[now] = {c[l]-c[l-1],c[l]-c[l-1]};
		return ;
	}
	int mid = (l+r)/2;
	build(l,mid,now*2),build(mid+1,r,now*2+1);
	tree[now] = tree[now*2]+tree[now*2+1];
}
void upd(int l,int r,int now,int ll,int rr){
	if(lazy[now]){
		tree[now].val = tree[now].sum-tree[now].val;
		if(l!=r)	lazy[now*2]^=1,lazy[now*2+1]^=1;
		lazy[now] = 0;
	}
	if(r<ll || l>rr)	return ;
	if(ll<=l && r<=rr){
		tree[now].val = tree[now].sum-tree[now].val;
		if(l!=r)	lazy[now*2]^=1,lazy[now*2+1]^=1;
		return ;
	}
	int mid = (l+r)/2;
	upd(l,mid,now*2,ll,rr),upd(mid+1,r,now*2+1,ll,rr);
	tree[now] = tree[now*2]+tree[now*2+1];
}
void solve(){
	int l,n;
	cin >> l >> n;
	rep(i,1,n+1){
		cin >> a[i];
		c.push_back(a[i]);
	}
	c.push_back(0);
	c.push_back(l);
	sort(all(c));
	c.resize(unique(all(c))-c.begin());
	n++;
	build(1,n,1);
	rep(i,1,n){
		int idx = lower_bound(all(c),a[i])-c.begin();
		upd(1,n,1,idx+1,n);
		cout << tree[1].val << '\n';
	}
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