/*
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Algo	: Persistent Segment Tree
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
	LL now = modN(a,b/2,c);
	if(b&1)	return (((now*now)%c)*(a%c))%c;
	else	return (now*now)%c;
}
struct A{
	int maxx,l,r;
	int lnode,rnode;
};
A tree[3000010];
PII a[100010];
int ver[100010];
int cnt;
int build(int l,int r){
	int now = ++cnt;
	if(l == r)	return now;
	int mid = (l+r)/2;
	tree[now] = {0,0,0,build(l,mid),build(mid+1,r)};
	return now;
}
void updtree(A &t,A l,A r,int lsz,int rsz){
	t.maxx = max({l.maxx,r.maxx,l.r+r.l});
	if(lsz == l.maxx)	t.l = lsz+r.l;
	else				t.l = l.l;
	if(rsz == r.maxx)	t.r = rsz+l.r;
	else				t.r = r.r;
}
int upd(int l,int r,A origin,int idx,int v=1){
	int now = ++cnt;
	if(l == r){
		tree[now] = {1,1,1,0,0};
		return now;
	}
	int mid = (l+r)/2;
	tree[now] = origin;
	if(idx<=mid)	tree[now].lnode = upd(l,mid,tree[origin.lnode],idx);
	else			tree[now].rnode = upd(mid+1,r,tree[origin.rnode],idx);
	updtree(tree[now],tree[tree[now].lnode],tree[tree[now].rnode],mid-l+1,r-mid);
	return now;
}
A ret;
A qry(int l,int r,A origin,int ll,int rr){
	if(l>rr || r<ll)	return {0,0,0,0,0};
	if(ll<=l && r<=rr)	return origin;
	int mid = (l+r)/2;
	updtree(ret,qry(l,mid,tree[origin.lnode],ll,rr),qry(mid+1,r,tree[origin.rnode],ll,rr),mid-l+1,r-mid);
	return ret;
}
int N;
void solve(){
	int L,R,W;
	cin >> L >> R >> W;
	int l = 1,r = N,mid;
	while(l<r){
		mid = (l+r)/2;
		if(qry(1,N,tree[ver[mid]],L,R).maxx>=W)	r = mid;
		else									l = mid+1;
	}
	cout << a[l].first << '\n';
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cin >> N;
	rep(i,1,N+1){
		cin >> a[i].first;
		a[i].second = i;
	}
	sort(a+1,a+N+1,greater<PII >());
	ver[0] = build(1,N);
	rep(i,1,N+1)
		ver[i] = upd(1,N,tree[ver[i-1]],a[i].second);
	int q = 1;
	cin >> q;
	for(int Q=1;Q<=q;Q++){
		// cout << "Case #" << Q << ": ";
		solve();
	}
	return 0;
}