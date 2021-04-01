/*
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Algo	: Segment tree
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
	if(b == 0)	return 0;
	if(b == 1)	return a%c;
	LL now = modN(a,b/2);
	if(b&1)	return (((now*now)%c)*(a%c))%c;
	else	return (now*now)%c;
}
int n;
LL tree[800010][2];
void build(int l,int r,int now = 1){
	if(l == r){
		tree[now][0] = l;
		tree[now][1] = -l;
		return ;
	}
	int mid = (l+r)/2;
	build(l,mid,now*2);	build(mid+1,r,now*2+1);
	tree[now][0] = max(tree[now*2][0],tree[now*2+1][0]);
	tree[now][1] = max(tree[now*2][1],tree[now*2+1][1]);
}
void upd(int state,int l,int r,int now,int idx,LL v){
	if(l == r){
		tree[now][state] = max(tree[now][state],v);
		return ;
	}
	int mid = (l+r)/2;
	if(idx<=mid)	upd(state,l,mid,now*2,idx,v);
	else			upd(state,mid+1,r,now*2+1,idx,v);
	tree[now][state] = max(tree[now*2][state],tree[now*2+1][state]);
}
LL query(int state,int l,int r,int now,int ll,int rr){
	if(r<ll || l>rr)	return -1e9;
	if(ll<=l && r<=rr)	return tree[now][state];
	int mid = (l+r)/2;
	return max(query(state,l,mid,now*2,ll,rr),query(state,mid+1,r,now*2+1,ll,rr));
}
LL maxx = 0;
void solve(){
	int u,v,w;
	cin >> u >> v >> w;
	//u-in v-out
	LL uu = w+max(query(0,1,n,1,1,u)-u,query(1,1,n,1,u,n)+u);
	//v-in u-out
	LL vv = w+max(query(0,1,n,1,1,v)-v,query(1,1,n,1,v,n)+v);
	//output
	maxx = maxN({maxx,uu,vv});
	cout << maxx << '\n';
	//update
	upd(0,1,n,1,v,uu+v);
	upd(1,1,n,1,v,uu-v);
	upd(0,1,n,1,u,vv+u);
	upd(1,1,n,1,u,vv-u);
}
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int q = 1;
	cin >> n >> q;
	build(1,n);
	for(int Q=1;Q<=q;Q++){
		// cout << "Case #" << Q << ": ";
		solve();
	}
	return 0;
}