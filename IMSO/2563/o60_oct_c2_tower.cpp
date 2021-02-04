/*
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Algo	:
	Status	: Unfinished
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
	if(b == 0)	return 0;
	if(b == 1)	return a%c;
	LL now = modN(a,b/2);
	if(b&1)	return (((now*now)%c)*(a%c))%c;
	else	return (now*now)%c;
}
struct A{
	int l,r,maxx,cnt;
};
A tree[800010];
int lazy[800010];
void build(int l,int r,int now){
	if(l == r){
		tree[now] = {0,0,0,1};
		return ;
	}
	int mid = (l+r)/2;
	build(l,mid,nl);
	build(mid+1,r,nr);
	tree[now] = {0,0,0,r-l+1};
}
void upd(int l,int r,int now,int ll,int rr,int v){
	if(lazy[now]){
		tree[now].l+=lazy[now];
		tree[now].r+=lazy[now];
		tree[now].maxx+=lazy[now];
		if(l!=r){
			lazy[nl]+=lazy[now];
			lazy[nr]+=lazy[now];
		}
		lazy[now] = 0;
	}
	if(ll>r || rr<l)	return ;
	if(ll<=l && r<=rr){
		tree[now].maxx+=v;
		tree[now].l+=v;
		tree[now].r+=v;
		if(l!=r){
			lazy[nl]+=v;
			lazy[nr]+=v;
		}
		return ;
	}
	int mid = (l+r)/2;
	upd(l,mid,nl,ll,rr,v);
	upd(mid+1,r,nr,ll,rr,v);
	if(tree[nl].maxx>tree[nr].maxx)			tree[now] = tree[nl];
	else if(tree[nr].maxx>tree[nl].maxx)	tree[now] = tree[nr];
	else{
		tree[now] = tree[nl];
		tree[now].cnt+=tree[nr].cnt;
		if(tree[nl].r == tree[nr].l && tree[nl].r == tree[now].maxx)	tree[now].cnt--;
	}
	tree[now].l = tree[nl].l,tree[now].r = tree[nr].r;
	// printf("%d %d: %d %d %d %d\n",l,r,tree[now].l,tree[now].r,tree[now].maxx,tree[now].cnt);
}
void solve(){
	int n,m,u,v,w;
	cin >> n >> m;
	build(1,n,1);
	while(m--){
		cin >> u >> v >> w;
		upd(1,n,1,u,v,w);
		cout << tree[1].maxx << ' ' << tree[1].cnt << '\n';
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