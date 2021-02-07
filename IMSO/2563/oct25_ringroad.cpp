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
	if(b == 0)	return 0;
	if(b == 1)	return a%c;
	LL now = modN(a,b/2);
	if(b&1)	return (((now*now)%c)*(a%c))%c;
	else	return (now*now)%c;
}
int tree[200010];
void upd(int idx,int v){
	while(idx<=200003){
		tree[idx]+=v;
		idx+=idx & -idx;
	}
}
int query(int idx,int sum=0){
	while(idx>0){
		sum+=tree[idx];
		idx-=idx & -idx;
	}
	return sum;
}
struct A{
	int v,w;
};
vector<A > g[200010];
struct B{
	int v,p,lv;
};
B h[200010];
void dfs(int now,int p){
	for(auto x:g[now]){
		h[x.v].v = h[now].v + x.w;
		h[x.v].lv = h[now].lv + 1;
		h[x.v].p = p;
		dfs(x.v,p);
	}
}
void solve(){
	int n,k,q,p,d;
	cin >> n >> k >> q;
	for(int i=1;i<=k;i++){
		cin >> d;
		upd(i,d);
	}
	for(int i=k+1;i<=n;i++){
		cin >> p >> d;
		g[p].push_back({i,d});
	}
	for(int i=1;i<=k;i++){
		h[i].p = i;
		dfs(i,i);
	}
	while(q--){
		int opr;
		cin >> opr;
		if(opr == 0){
			//change distance
			cin >> p >> d;
			int temp = query(p) - query(p-1);
			upd(p,-temp);	upd(p,d);
		}else{
			//ask
			cin >> p >> d;
			int ans = h[p].v + h[d].v;
			if(h[p].p == h[d].p){
				if(h[p].lv>h[d].lv)	swap(p,d);
				ans = h[d].v - h[p].v;
			}
			p = h[p].p,d = h[d].p;
			// printf("progress: %d %d %d\n",ans,p,d);
			if(p>d)	swap(p,d);
			ans+=min(query(d-1) - query(p-1),query(p-1) + (query(k) - query(d-1)));
			cout << ans << '\n';
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