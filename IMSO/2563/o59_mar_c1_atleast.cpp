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
	int num;
	LL sum;
	int l,r;
};
A tree[2000010];
vector<int > c;
int a[100010];
int ver[100010];
int cnt;
int N;
int build(int l,int r){
	int now = ++cnt;
	if(l == r)	return now;
	int mid = (l+r)/2;
	tree[now] = {0,0,build(l,mid),build(mid+1,r)};
	return now;
}
int upd(int l,int r,A origin,int idx,int v){
	int now = ++cnt;
	tree[now] = origin;
	tree[now].num++,tree[now].sum+=v;
	if(l == r)	return now;
	int mid = (l+r)/2;
	if(idx<=mid)	tree[now].l = upd(l,mid,tree[origin.l],idx,v);
	else			tree[now].r = upd(mid+1,r,tree[origin.r],idx,v);
	return now;
}
//sum of K number
LL query(int l,int r,A ll,A rr,int k){
	// printf("%d %d %d\n",l,r,k);
	if(k<=0)				return 0;
	if(l == r)				return min(k,rr.num-ll.num)*c[l];
	if(k>=rr.num-ll.num)	return rr.sum-ll.sum;
	int mid = (l+r)/2;
	return query(l,mid,tree[ll.l],tree[rr.l],min(tree[rr.l].num-tree[ll.l].num,k))
		+ query(mid+1,r,tree[ll.r],tree[rr.r],k-min(tree[rr.l].num-tree[ll.l].num,k));
}
void solve(){
	int st,en;
	double u,v;
	LL all;
	cin >> st >> en >> u;
	all = tree[ver[en]].sum-tree[ver[st-1]].sum,v = (en-st+1)*u;
	if(all>=v){
		cout << "0\n";
		return ;
	}
	int l=1,r=(en-st+1),mid;
	while(l<r){
		mid = (l+r)/2,v = ((en-st+1)-mid)*u;
		if(all-query(1,sz(c)-1,tree[ver[st-1]],tree[ver[en]],mid)>=v)	r = mid;
		else															l = mid+1;
	}
	if(l == (en-st+1))	cout << "-1\n";
	else				cout << l << '\n';
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int q = 1;
	cin >> N >> q;
	for(int i=1;i<=N;i++)
		cin >> a[i],c.push_back(a[i]);
	c.push_back(-1e9);
	sort(all(c));	c.resize(unique(all(c))-c.begin());
	ver[0] = build(1,sz(c)-1);
	for(int i=1;i<=N;i++)
		ver[i] = upd(1,sz(c)-1,tree[ver[i-1]],lower_bound(all(c),a[i])-c.begin(),a[i]);
	for(int Q=1;Q<=q;Q++){
		// cout << "Case #" << Q << ": ";
		solve();
	}
	return 0;
}