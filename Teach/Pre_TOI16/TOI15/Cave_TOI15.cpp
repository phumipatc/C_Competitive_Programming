/*
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Algo	: Dijkstra, Observe that maximum path is n-1 edges
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
	LL v,w,state;
	bool operator < (const A&o) const{
		return w>o.w;
	}
};
priority_queue<A > heap;
LL dis[2010][2010];
vector<A > g[2010];
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int n,m,st,en,u,v,w;
	cin >> n >> st >> en >> m;
	while(m--){
		cin >> u >> v >> w;
		g[u].push_back({v,w,0});
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			dis[i][j] = 1e18;
	dis[st][0] = 0;
	heap.push({st,0,0});
	while(!heap.empty()){
		auto now = heap.top();
		heap.pop();
		for(auto x:g[now.v]){
			int nst = now.state+1-(now.v == st || x.v == st);
			if(dis[x.v][nst]<=now.w+x.w)	continue;
			dis[x.v][nst] = now.w+x.w;
			heap.push({x.v,now.w+x.w,nst});
		}
	}
	// for(int i=0;i<n;i++)
	// 	printf("%lld ",dis[en][i]);
	// printf("\n");
	int q;
	LL minn;
	cin >> q;
	while(q--){
		cin >> w;
		minn = 1e18;
		for(int i=0;i<n;i++)
			minn = min(minn,dis[en][i] + i*w);
		cout << minn << ' ';
	}
	return 0;
}
/*
8 0 7 14
0 1 10
0 3 14
0 4 8
1 2 2
2 7 2
2 3 4
3 7 15
3 4 9
5 3 7
5 7 2
4 5 5
4 6 1
6 5 1
6 4 3
4
0 10 2 30
*/