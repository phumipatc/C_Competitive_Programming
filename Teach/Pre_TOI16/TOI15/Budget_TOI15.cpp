/*
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Algo	: MST
	Status	: Finished
*/
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int ,int >;
using PLL = pair<long long ,long long >;
const int dir4[2][4] = {{1,-1,0,0},{0,0,1,-1}};
const int dir8[2][8] = {{-1,-1,-1,0,1,1,1,0},{-1,0,1,1,-1,0,1,-1}};
struct A{
	int u,v,w,state;
	bool operator < (const A&o) const{
		return w>o.w;
	}
};
priority_queue<A > heap;
vector<PII > pack;
vector<A > g;
int p[3010],bs[500010];
int fr(int u){
	if(p[u] == u)	return u;
	else			return p[u] = fr(p[u]);
}
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int n,m,u,v,w,state,ru,rv,k;
	cin >> n >> m;
	for(int i=0;i<n;i++)
		p[i] = i;
	while(m--){
		cin >> u >> v >> w >> state;
		if(state){
			ru = fr(u);
			rv = fr(v);
			p[ru] = rv;
		}else
			g.push_back({u,v,w,state});
	}
	cin >> k;
	for(int i=1;i<=k;i++){
		cin >> u >> v;
		pack.push_back({u,v});
	}
	sort(pack.begin(),pack.end());
	bs[k] = pack[pack.size()-1].second;
	for(int i=pack.size()-2;i>=0;i--){
		pack[i].second = min(pack[i].second,pack[i+1].second);
		bs[i] = pack[i].first;
	}
	// for(int i=1;i<=k;i++)
		// printf("%d ",bs[i]);
	for(auto x:g){
		w = lower_bound(bs,bs+k,x.w)-bs;
		// printf("%d %d %d %d\n",x.u,x.v,x.w,pack[w].second);
		heap.push({x.u,x.v,pack[w].second,0});
	}
	LL ans = 0;
	while(!heap.empty()){
		auto now = heap.top();
		heap.pop();
		ru = fr(now.u);
		rv = fr(now.v);
		if(ru == rv)	continue;
		ans+=now.w;
		p[ru] = rv;
	}
	cout << ans << '\n';
	return 0;
}