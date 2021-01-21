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
int v[100010];
PII tree[400010];
void build(int l,int r,int now){
	if(l == r){
		tree[now] = {l,l};
		return ;
	}
	int mid = (l+r)/2;
	build(l,mid,now*2);
	build(mid+1,r,now*2+1);
	tree[now] = {tree[now*2].first,tree[now*2+1].second};
}
void upd(int l,int r,int now,int idx,int v){
	if(l == r){
		tree[now] = {v,v};
		return ;
	}
	int mid = (l+r)/2;
	if(idx<=mid)	upd(l,mid,now*2,idx,v);
	else			upd(mid+1,r,now*2+1,idx,v);
	tree[now] = {min(tree[now*2].first,tree[now*2+1].first),max(tree[now*2].second,tree[now*2+1].second)};
}
PII query(int l,int r,int now,int ll,int rr){
	if(r<ll || rr<l)	return {(int )1e9,(int )-1e9};
	// printf("%d %d %d %d %d\n",l,r,now,ll,rr);
	if(ll<=l && r<=rr)	return tree[now];
	int mid = (l+r)/2;
	PII ql = query(l,mid,now*2,ll,rr),qr = query(mid+1,r,now*2+1,ll,rr);
	return {min(ql.first,qr.first),max(ql.second,qr.second)};
}
void solve(){
	int n,m,opr,a,b;
	PII now;
	cin >> n >> m;
	for(int i=1;i<=n;i++)
		v[i] = i;
	build(1,n,1);
	while(m--){
		cin >> opr >> a >> b;
		a++,b++;
		if(opr == 0){
			swap(v[a],v[b]);
			upd(1,n,1,a,v[a]);
			upd(1,n,1,b,v[b]);
		}else{
			now = query(1,n,1,a,b);
			// printf("%d %d\n",now.first,now.second);
			if(now.first == a && now.second == b)	cout << "YES\n";
			else									cout << "NO\n";
		}
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