/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
struct A{
	int v,w,p,last;
	bool operator < (const A&o) const{
		if(w!=o.w)	return w>o.w;
		else		return p<o.p;
	}
};
A now;
priority_queue<A > heap;
vector<A > g[1010];
int c[1010],dis[1010][110],back[1010];
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	// freopen("in.txt","r",stdin);
	// freopen("out.txt","w",stdout);
	int q,n,m,k,u,v,w;
	cin >> q;
	for(int t=1;t<=q;t++){
		cin >> n >> m >> k;
		for(int i=0;i<n;i++)
			cin >> c[i];
		while(m--){
			cin >> u >> v >> w;
			g[u].push_back({v,w,0,0});
			g[v].push_back({u,w,0,0});
		}
		for(int i=0;i<n;i++){
			back[i] = 1e9;
			for(int j=0;j<=k;j++)
				dis[i][j] = 1e9;
		}
		heap.push({0,0,0,0});
		back[0] = 0;
		while(!heap.empty()){
			now = heap.top();
			heap.pop();
			if(back[now.v]<now.w)	continue;
			for(auto x:g[now.v]){
				if(back[x.v]<=now.w+x.w)	continue;
				back[x.v] = now.w+x.w;
				heap.push({x.v,x.w,0,0}); 
			}
		}
		heap.push({0,0,0,-1});
		dis[0][0] = 0;
		int ans = 1e9;
		while(!heap.empty()){
			now = heap.top();
			heap.pop();
			// printf("%d %d %d %d\n",now.v,now.w,now.p,now.last);
			if(dis[now.v][now.p]<now.w)	continue;
			if(now.p == k){
				ans = min(ans,now.w+back[now.v]);
				continue;
			}
			for(auto x:g[now.v]){
				if(now.p<k && dis[x.v][now.p+1]>now.w+c[x.v]+x.w){
					dis[x.v][now.p+1] = now.w+c[x.v]+x.w;
					heap.push({x.v,now.w+c[x.v]+x.w,now.p+1,x.v});
				}
				if(dis[x.v][now.p]<=now.w+x.w)	continue;
				dis[x.v][now.p] = now.w+x.w;
				heap.push({x.v,now.w+x.w,now.p,now.v});
			}
		}
		cout << "Case #" << t << ": ";
		cout << ans << '\n';
		for(int i=0;i<n;i++)
			g[i].clear();
	}
	return 0;
}