/*
	Task	: Meteors
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Created	: 30 April 2021 [14:39]
	Algo	: Parallel Binary Search
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
using LL = unsigned long long;
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
	int l,r,v;
};
A a[300010];
vector<int > pos[300010],ask[300010];
A met[300010];
int t[300010];
LL tree[300010];
void upd(int idx,int v=1){
	for(;idx<=300003;idx+=idx&-idx)
		tree[idx]+=v;
}
LL query(int idx,LL sum=0){
	for(;idx;idx-=idx&-idx)
		sum+=tree[idx];
	return sum;
}
void solve(){
	int n,m,v,k;
	cin >> n >> m;
	for(int i=1;i<=m;i++)
		cin >> v,pos[v].push_back(i);
	for(int i=1;i<=n;i++)
		cin >> t[i];
	cin >> k;
	for(int i=1;i<=n;i++)
		a[i] = {1,k+1};
	for(int i=1;i<=k;i++)
		cin >> met[i].l >> met[i].r >> met[i].v;
	while(1){
		for(int i=1;i<=k;i++)
			ask[i].clear();
		int cnt=0;
		for(int i=1;i<=n;i++)
			ask[(a[i].l+a[i].r)/2].push_back(i),cnt+=(a[i].l == a[i].r);
		if(cnt == n)	break;
		for(int i=1;i<=k;i++){
			if(met[i].l<=met[i].r){
				upd(met[i].l,met[i].v);
				upd(met[i].r+1,-met[i].v);
			}else{
				upd(met[i].l,met[i].v);
				upd(m+1,-met[i].v);
				upd(1,met[i].v);
				upd(met[i].r+1,-met[i].v);
			}
			for(auto x:ask[i]){
				LL sum=0;
				for(auto y:pos[x])
					sum+=query(y);
				if(sum>=t[x])	a[x].r = i;
				else			a[x].l = i+1;
			}
		}
		for(int i=1;i<=k;i++){
			if(met[i].l<=met[i].r){
				upd(met[i].l,-met[i].v);
				upd(met[i].r+1,met[i].v);
			}else{
				upd(met[i].l,-met[i].v);
				upd(m+1,met[i].v);
				upd(1,-met[i].v);
				upd(met[i].r+1,met[i].v);
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i].l == k+1)	cout << "NIE\n";
		else				cout << a[i].l << '\n';
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