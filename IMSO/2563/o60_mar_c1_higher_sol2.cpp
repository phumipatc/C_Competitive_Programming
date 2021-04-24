/*
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Algo	: Segment Tree
	Status	: Finished
*/
#include<bits/stdc++.h>
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
	if(b == 0)	return 0;
	if(b == 1)	return a%c;
	LL now = modN(a,b/2);
	if(b&1)	return (((now*now)%c)*(a%c))%c;
	else	return (now*now)%c;
}
int tree[4000010];
void upd(int l,int r,int now,int idx,int v){
	if(l == r){
		tree[now] = v;
		return ;
	}
	int mid = (l+r)/2;
	if(idx<=mid)	upd(l,mid,now*2,idx,v);
	else			upd(mid+1,r,now*2+1,idx,v);
	tree[now] = max(tree[now*2],tree[now*2+1]);
}
int query(int l,int r,int now,int ll,int rr){
	if(r<ll || l>rr)	return 0;
	if(ll<=l && r<=rr)	return tree[now];
	int mid = (l+r)/2;
	return max(query(l,mid,now*2,ll,rr),query(mid+1,r,now*2+1,ll,rr));
}
void solve(){
	int n,k,pos,h;
	cin >> n >> k;
	while(k--){
		cin >> pos >> h;
		pos++;
		upd(1,n,1,pos,h);
		int l = 0,r = n,mid;
		while(l<r){
			mid = (l+r+1)/2;
			if(query(1,n,1,max(1,pos-mid),min(n,pos+mid)) == h)	l = mid;
			else												r = mid-1;
		}
		// printf("max: %d\n",l);
		if(pos-l<1 && pos+l>n)	cout << n << '\n';
		else					cout << l << '\n';
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
/*
10 8
3 1
7 3
5 2
5 1
7 5
4 2
3 2
2 2

*/