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
	int v,r;
};
A p[200010];
map<int ,int > mapp[200010];
map<int ,int > del,now;
int st[100010],en[100010];
void solve(){
	int k,m,l,last;
	cin >> k >> m;
	int id = 1;
	for(int i=1;i<=k;i++){
		cin >> l;
		last = 0;
		st[i] = id;
		while(l--){
			cin >> p[id].v;
			p[last].r = id;
			last = id;
			id++;
			en[i] = id;
			p[id].v = 2e9;
		}
		p[last].r = id;
		// printf("%d %d\n",st[i],en[i]);
		id++;
	}
	int opr,u,v,idx;
	while(m--){
		cin >> opr >> u >> v;
		if(opr == 1){
			// printf("mark from %d to %d\n",st[u],en[u]);
			mapp[st[u]][v]++;
			mapp[en[u]][v]--;
		}else{
			// printf("value: %d %d %d\n",st[v],en[u],en[v]);
			p[en[u]].r = st[v];
			del[st[v]] = 1;
			en[u] = en[v];
		}
	}
	for(int i=1;i<=k;i++){
		if(del[st[i]])	continue;
		// printf("%d\n",st[i]);
		now.clear();
		idx = st[i];
		now = mapp[st[i]];
		now[2e9] = 1;
		while(idx!=0){
			// printf("idx: %d\n",idx);
			if(p[idx].v == 2e9 || del[idx]){
				for(auto x:mapp[idx])
					now[x.first]+=x.second;
			}
			if(!now[p[idx].v])	cout << p[idx].v << '\n';
			idx = p[idx].r;
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