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
	int l,r,v;
};
A tree[300010];
int ver[100010];
int num;
int build(int l,int r){
	num++;
	int now = num;
	if(l == r)	return now;
	int mid = (l+r)/2;
	tree[now] = {build(l,mid),build(mid+1,r),0};
}
int upd(int l,int r,A origin,int idx,int v){
	num++;
	if(l == r){
		tree[num] = {0,0,1};
		return num;
	}
	int mid = (l+r)/2,now = num;
	if(idx<=mid)	tree[now] = {upd(l,mid,tree[origin.l],idx,v),origin.r,origin.v+v};
	else			tree[now] = {origin.l,upd(mid+1,r,tree[origin.r],idx,v),origin.v+v};
	return now;
}
int query(int l,int r,A ll,A rr,int k){
	if(l == r)	return l;
	int mid = (l+r)/2,num = tree[rr.l].v-tree[ll.l].v;
	// printf("%d %d %d %d\n",l,r,tree[ll.l].v,tree[rr.l].v);
	if(num<k)	return query(mid+1,r,tree[ll.r],tree[rr.r],k-num);
	else		return query(l,mid,tree[ll.l],tree[rr.l],k);
}
int a[100010];
void solve(){
	int n,m,i,j,k;
	cin >> n >> m;
	vector<int > v(n+1);
	for(int i=1;i<=n;i++)
		cin >> a[i],v[i] = a[i];
	sort(allst(v,1));
	build(1,n);
	for(int i=1;i<=n;i++)
		a[i] = lower_bound(allst(v,1),a[i])-v.begin();
	ver[0] = 1;
	for(int i=1;i<=n;i++)
		ver[i] = upd(1,n,tree[ver[i-1]],a[i],1);
	while(m--){
		cin >> i >> j >> k;
		cout << v[query(1,n,tree[ver[i-1]],tree[ver[j]],k)] << '\n';
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