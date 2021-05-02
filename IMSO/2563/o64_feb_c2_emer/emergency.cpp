/*
	Task	: emergency
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Created	: 02 May 2021 [18:26]
	Algo	: DP on tree
	Status	: Finished
*/
#include<bits/stdc++.h>
#include "emergency.h"
#define rep(i, a, b) for(int i = a; i < (b); ++i)
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
	if(b == 0)	return 1;
	if(b == 1)	return a%c;
	LL now = modN(a,b/2,c);
	if(b&1)	return (((now*now)%c)*(a%c))%c;
	else	return (now*now)%c;
}
struct A{
	int v,w;
};
vector<A > g[200010];
int hos[200010],cen[200010];
struct B{
	int v,dh,dc;
};
int maxx;
B dfs(int u,int p){
	B now = {(int )-1e9,(hos[u]?0:(int )-1e9),(cen[u]?0:(int )-1e9)};
	for(auto x:g[u]){
		if(x.v == p)	continue;
		B ret = dfs(x.v,u);
		now.v = max({now.v,now.dc + ret.dh + x.w,now.dh + ret.dc + x.w});
		now.dh = max(now.dh,ret.dh + x.w);
		now.dc = max(now.dc,ret.dc + x.w);
	}
	// printf("%d %d %d %d\n",u,now.v,now.dh,now.dc);
	maxx = max(maxx,now.v);
	return now;
}
int furthest(int N, int H, int K,
	     int roads[][2],
	     int lengths[],
	     int hospitals[],
	     int centers[])
{
	rep(i,0,N-1){
		int u = roads[i][0],v = roads[i][1],w = lengths[i];
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	rep(i,0,H)
		hos[hospitals[i]] = 1;
	rep(i,0,K)
		cen[centers[i]] = 1;
	dfs(0,-1);
	return maxx;
}
// static const int MAX_N = 200010;
// static int N, H, K;
// static int roads[MAX_N][2];
// static int lengths[MAX_N];
// static int hospitals[MAX_N];
// static int centers[MAX_N];

// int main()
// {
//   scanf("%d %d %d",&N,&H,&K);
//   for(int i=0; i<H; i++) {
//     scanf("%d",&hospitals[i]);
//   }
//   for(int i=0; i<K; i++) {
//     scanf("%d",&centers[i]);
//   }
//   for(int i=0; i<N-1; i++) {
//     scanf("%d %d %d",&roads[i][0], &roads[i][1], &lengths[i]);
//   }
//   printf("%d\n",furthest(N, H, K,
// 			 roads, lengths,
// 			 hospitals, centers));
// }
