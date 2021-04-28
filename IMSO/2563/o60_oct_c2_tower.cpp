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
#define nl now*2
#define nr now*2+1
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
	int mx,cnt,l,r;
};
A tree[800010];
void build(int l,int r,int now){
	if(l == r){
		tree[now].cnt = 1;
		return ;
	}
	int mid = (l+r)/2;
	build(l,mid,now*2);	build(mid+1,r,now*2+1);
	tree[now].cnt = 1;
}
int lazy[800010];
void upd(int l,int r,int now,int ll,int rr,int v){
	if(lazy[now]){
		tree[now].mx+=lazy[now];
		tree[now].l+=lazy[now];
		tree[now].r+=lazy[now];
		if(l!=r)	lazy[now*2]+=lazy[now],lazy[now*2+1]+=lazy[now];
		lazy[now] = 0;
	}
	if(l>rr or r<ll)	return ;
	if(ll<=l and r<=rr){
		tree[now].mx+=v;
		tree[now].l+=v;
		tree[now].r+=v;
		if(l!=r)	lazy[now*2]+=v,lazy[now*2+1]+=v;
		return ;
	}
	int mid = (l+r)/2;
	upd(l,mid,now*2,ll,rr,v);	upd(mid+1,r,now*2+1,ll,rr,v);
	A tl = tree[now*2],tr = tree[now*2+1];
	// printf("%d %d (%d,%d) (%d,%d)\n",l,r,tl.mx,tl.cnt,tr.mx,tr.cnt);
	if(tl.mx>tr.mx)			tree[now] = tl,tree[now].r = tr.r;
	else if(tl.mx<tr.mx)	tree[now] = tr,tree[now].l = tl.l;
	else{
		tree[now] = {tl.mx,tl.cnt + tr.cnt,tl.l,tr.r};
		if(tl.r == tr.l and tl.r == tl.mx)	tree[now].cnt--;
	}
}
void solve(){
	int n,m,a,b,x;
	cin >> n >> m;
	build(1,n,1);
	while(m--){
		cin >> a >> b >> x;
		upd(1,n,1,a,b,x);
		cout << tree[1].mx << ' ' << tree[1].cnt << '\n';
	}
}
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int q = 1;
	// cin >> q;
	while(q--){
		solve();
	}
	return 0;
}