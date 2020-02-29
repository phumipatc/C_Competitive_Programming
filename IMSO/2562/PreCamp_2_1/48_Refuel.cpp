/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
struct A{
	int v,w,f;
	bool operator < (const A&o) const{
		if(w!=o.w)	return w>o.w;
		else		return f<o.f;
	}
};
A now;
priority_queue<A > heap;
vector<A > g[1010];
int dis[1010][110],p[1010];
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int q,n,m,u,v,w,c,st,en;
	cin >> q;
	while(q--){
		cin >> n >> m;
		for(int i=0;i<n;i++)
			cin >> p[i];
		while(m--){
			cin >> u >> v >> w;
			g[u].push_back({v,w,0});
			g[v].push_back({u,w,0});
		}
		cin >> c >> st >> en;
		for(int i=0;i<n;i++)
			for(int j=0;j<=c;j++)
				dis[i][j] = 1e9;
		dis[st][0] = 0;
		heap.push({st,0,0});
		bool ans = false;
		while(!heap.empty()){
			now = heap.top();
			heap.pop();
			if(now.v == en){
				printf("%d\n",now.w);
				ans = true;
				break;
			}
			if(now.f<c && dis[now.v][now.f+1]>now.w+p[now.v]){
				dis[now.v][now.f+1] = now.w+p[now.v];
				heap.push({now.v,dis[now.v][now.f+1],now.f+1});
			}
			for(auto x:g[now.v]){
				if(now.f<x.w)					continue;
				if(dis[x.v][now.f-x.w]<=now.w)	continue;
				dis[x.v][now.f-x.w] = now.w;
				heap.push({x.v,now.w,now.f-x.w});
			}
		}
		if(!ans)	printf("-99\n");
		while(!heap.empty())	heap.pop();
		for(int i=0;i<n;i++)
			g[i].clear();
	}
	return 0;
}
/*
2
5 5
10 10 20 12 13
0 1 9
0 2 8
1 2 1
1 3 11
2 3 7
10 0 3
5 5
10 10 20 12 13
0 1 9
0 2 8
1 2 1
1 3 11
2 3 7
20 1 4
*/