/*
	Task	: bestbank
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 25 May 2021 [13:19]
	Algo	: 
	Status	: 
*/
#include<bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i <= (b); ++i)
#define repr(i, a, b) for(int i = a; i >= (b); --i)
#define all(x) begin(x),end(x)
#define allst(x,y) (x).begin()+y,(x).end()
#define rmdup(x) (x).resize(unique((x).begin(),(x).end())-(x).begin())
#define sz(x) (int)(x).size()
#define decp(x) fixed << setprecision(x)
#define MOD (LL )(1e9+7)
using namespace std;
using LL = long long;
using PII = pair<int ,int >;
using PLL = pair<long long ,long long >;
const int dir4[2][4] = {{1,-1,0,0},{0,0,1,-1}};
const int dir8[2][8] = {{-1,-1,-1,0,1,1,1,0},{-1,0,1,1,-1,0,1,-1}};
LL modN(LL a,LL b,LL c = MOD){
	if(b == 0)	return 1;
	if(b == 1)	return a%c;
	LL now = modN(a,b/2,c);
	if(b&1)	return (((now*now)%c)*(a%c))%c;
	else	return (now*now)%c;
}
#include "bestbank.h"
const int N = (1e5+10);
const int BASE = (1e5+5);
vector<PII > g[N];
int p[N],vis[N],sz[N];
int LCA[N][20],lv[N];
LL dis[N],dp[N];
void init_LCA(int u,int pa,int lvl,int w){
	LCA[u][0] = pa;
	lv[u] = lvl;
	dis[u] = dis[pa]+w;
	rep(i,1,18)
		LCA[u][i] = LCA[LCA[u][i-1]][i-1];
	for(auto x:g[u]){
		if(x.first == pa)	continue;
		init_LCA(x.first,u,lvl+1,x.second);
	}
}
int find_size(int u,int pa = BASE){
	if(vis[u])	return 0;
	sz[u] = 1;
	for(auto x:g[u]){
		if(x.first == pa)	continue;
		sz[u]+=find_size(x.first,u);
	}
	return sz[u];
}
int find_centroid(int u,int pa,int n){
	for(auto x:g[u]){
		if(x.first == pa)		continue;
		if(vis[x.first])		continue;
		if(sz[x.first]<=n/2)	continue;
		return find_centroid(x.first,u,n);
	}
	return u;
}
int init_centroid(int u,int pa){
	find_size(u);
	int c = find_centroid(u,pa,sz[u]);
	vis[c] = 1;
	p[c] = pa;
	for(auto x:g[c]){
		if(vis[x.first])	continue;
		init_centroid(x.first,c);
	}
}
int find_LCA(int u,int v){
	if(lv[u]<lv[v])	swap(u,v);
	repr(i,18,0){
		if(LCA[u][i] == BASE || lv[LCA[u][i]]<lv[v])	continue;
		u = LCA[u][i];
	}
	if(u == v)	return u;
	repr(i,18,0){
		if(LCA[u][i] == BASE || LCA[v][i] == BASE || LCA[u][i] == LCA[v][i])	continue;
		u = LCA[u][i],v = LCA[v][i];
	}
	return LCA[u][0];
}
LL find_dis(int u,int v){
	int pa = find_LCA(u,v);
	return dis[u] + dis[v] - (2*dis[pa]);
}
void upd(int u,int v,int F,LL L){
	while(u!=BASE){
		dp[u] = min(dp[u],find_dis(u,v) + L);
		u = p[u];
	}
}
LL read(int u,int v,int S){
	LL mn = 1e18;
	while(u!=BASE){
		mn = min(mn,find_dis(u,v) + dp[u]);
		u = p[u];
	}
	return mn;
}
void initialize(int N, int K,std::vector<std::vector<int> > R,std::vector<std::vector<long long> > B)
{
	for(auto x:R){
		g[x[0]].push_back({x[1],x[2]});
		g[x[1]].push_back({x[0],x[2]});
	}
	rep(i,0,18)
		LCA[BASE][i] = BASE;
	init_LCA(0,BASE,1,0);
	init_centroid(0,BASE);
	fill(dp,dp+N,1e18);
	for(auto x:B)
		upd(x[0],x[0],x[1],x[2]);
}

void update_bank(int P, int F,long long L)
{
	upd(P,P,F,L);
}

long long find_best_bank(int S, int Y)
{
	return read(S,S,Y);
}
/*
5 2 2
0 2 15
1 2 6
2 3 5
3 4 7
1 0 3
4 0 5
*/