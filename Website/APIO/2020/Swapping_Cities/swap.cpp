/*
	Task	: swap
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 13 May 2021 [12:22]
	Algo	: 
	Status	: 
*/
#include<bits/stdc++.h>
#include "swap.h"
#define rep(i, a, b) for(int i = a; i < (b); ++i)
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
struct A{
	int u,v,w;
	bool operator < (const A&o) const{
		return w<o.w;
	}
};
const int mxN = 300010;
vector<A > edges;
int p[mxN],deg[mxN],mx[mxN];
bool hide[mxN];
int fr(int u){
	return (u == p[u])?u:p[u] = fr(p[u]);
}
int LCA[mxN][20],lv[mxN];
void init(int N, int M,
          std::vector<int> U, std::vector<int> V, std::vector<int> W) {
	iota(p,p+N+M,0);
	for(int i=0;i<N+M;i++)
		LCA[i][0] = i;
	for(int i=0;i<M;i++)
		edges.push_back({U[i],V[i],W[i]});
	sort(all(edges));
	int cnt = N;
	for(auto x:edges){
		int ru = fr(x.u),rv = fr(x.v);
		p[ru] = p[rv] = cnt;
		LCA[ru][0] = LCA[rv][0] = cnt;
		deg[x.u]++,deg[x.v]++;
		// Check if this path can hide
		mx[cnt] = x.w;
		if(ru == rv || deg[x.u]>2 || deg[x.v]>2 || hide[ru] || hide[rv])	hide[cnt] = true;
		cnt++;
	}
	for(int i=cnt-1;i>=0;i--){
		for(int j=1;j<=17;j++)
			LCA[i][j] = LCA[LCA[i][j-1]][j-1];
		lv[i] = lv[LCA[i][0]] + 1;
	}
}
int find_LCA(int u,int v){
	if(lv[u]<lv[v])	swap(u,v);
	for(int i=17;i>=0;i--){
		if(lv[LCA[u][i]]<lv[v])	continue;
		u = LCA[u][i];
	}
	if(u == v)	return u;
	for(int i=17;i>=0;i--){
		if(LCA[u][i] == LCA[v][i])	continue;
		u = LCA[u][i],v = LCA[v][i];
	}
	return LCA[u][0];
}
int getMinimumFuelCapacity(int X, int Y) {
	int pa = find_LCA(X,Y);
	if(hide[pa])	return mx[pa];
	for(int i=17;i>=0;i--){
		if(hide[LCA[pa][i]])	continue;
		pa = LCA[pa][i];
	}
	pa = LCA[pa][0];
	return (hide[pa]?mx[pa]:-1);
}
// int main() {
//   int N, M;
//   assert(2 == scanf("%d %d", &N, &M));
  
//   std::vector<int> U(M), V(M), W(M);
//   for (int i = 0; i < M; ++i) {
//     assert(3 == scanf("%d %d %d", &U[i], &V[i], &W[i]));
//   }

//   int Q;
//   assert(1 == scanf("%d", &Q));

//   std::vector<int> X(Q), Y(Q);
//   for (int i = 0; i < Q; ++i) {
//     assert(2 == scanf("%d %d", &X[i], &Y[i]));
//   }

//   init(N, M, U, V, W);
  
//   std::vector<int> minimum_fuel_capacities(Q);
//   for (int i = 0; i < Q; ++i) {
//     minimum_fuel_capacities[i] = getMinimumFuelCapacity(X[i], Y[i]);
//   }

//   for (int i = 0; i < Q; ++i) {
//     printf("%d\n", minimum_fuel_capacities[i]);
//   }
  
//   return 0;
// }
