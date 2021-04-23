/*
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Algo	: Segment Tree
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
int tree[800010];
void upd(int l,int r,int now,int idx,int v){
	if(l == r){
		tree[now] = v;
		return ;
	}
	int mid = (l+r)/2;
	if(idx<=mid)	upd(l,mid,now*2,idx,v);
	else			upd(mid+1,r,now*2+1,idx,v);
	tree[now] = tree[now*2]+tree[now*2+1];
}
int sum(int l,int r,int now,int ll,int rr){
	if(ll<=l && r<=rr)	return tree[now];
	if(r<ll || l>rr)	return 0;
	int mid = (l+r)/2;
	return sum(l,mid,now*2,ll,rr)+sum(mid+1,r,now*2+1,ll,rr);
}
int kpos(int l,int r,int now,int v){
	if(l == r)	return l;
	int mid = (l+r)/2;
	if(v<=tree[now*2])	return kpos(l,mid,now*2,v);
	else				return kpos(mid+1,r,now*2+1,v-tree[now*2]);
}
void build(int l,int r,int now){
	if(l == r){
		tree[now] = 1;
		return ;
	}
	int mid = (l+r)/2;
	build(l,mid,now*2),build(mid+1,r,now*2+1);
	tree[now] = tree[now*2]+tree[now*2+1];
}
void solve(){
	int n,k,pos;
	cin >> n >> k;
	build(1,n,1);
	upd(1,n,1,k,0),pos = k;
	for(int i=n-1;i>1;i--){
		k = (k%i)?k%i:i;
		// printf("%d\n",sum(1,n,1,pos+1,n));
		if(k<=sum(1,n,1,pos+1,n))	pos = kpos(1,n,1,sum(1,n,1,1,pos-1)+k);
		else						pos = kpos(1,n,1,k-sum(1,n,1,pos+1,n));
		upd(1,n,1,pos,0);
		// printf("%d %d\n",k,pos);
		k = pos;
	}
	cout << kpos(1,n,1,1);
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