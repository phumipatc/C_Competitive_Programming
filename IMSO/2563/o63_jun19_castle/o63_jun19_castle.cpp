/*
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Algo	:
	Status	: 75 pt. 4T
*/
#include <bits/stdc++.h>
#include "castle.h"
using namespace std;
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

int N,M,Q,Y;
vector<int> A,B,temp;
set<int > edge;
vector<int > g[100010];
int p[100010],mark[100010];
int fr(int u){
	return (p[u] == u?u:fr(p[u]));
}
int frcp(int u){
	return p[u] = (p[u] == u?u:fr(p[u]));
}
void dfs(int u,int pa){
	p[u] = pa;
	for(auto x:g[u]){
		if(x == pa)	continue;
		dfs(x,u);
	}
}
int dfs2(int u,int v){
	if(u == v)	return 1;
	mark[u] = 1;
	temp.push_back(u);
	for(auto x:edge){
		int ru = fr(A[x]),rv = fr(B[x]);
		if(ru == rv)	continue;
		else if(ru == u){
			if(mark[rv])	continue;
			if(dfs2(rv,v))	return 1;
		}else if(rv == u){
			if(mark[ru])	continue;
			if(dfs2(ru,v))	return 1;
		}
	}
	return 0;
}
int main() {
	castle_init(N,M,Q,Y);
	castle_read_map(A,B);
	int ru,rv;
	iota(p,p+N,0);
	for(int i=0;i<M;i++){
		ru = frcp(A[i]),rv = frcp(B[i]);
		if(ru == rv){
			edge.insert(i);
			continue;
		}
		p[ru] = rv;
		g[A[i]].push_back(B[i]);
		g[B[i]].push_back(A[i]);
	}
	dfs(0,0);
	while (Q--) {
		int T,X,Y;
		castle_read_event(T,X,Y);
		if(T == 1){
			if(edge.find(X) == edge.end()){
				//normal edge
				if(p[A[X]] == B[X])	p[A[X]] = A[X];
				else				p[B[X]] = B[X];
			}else	edge.erase(X);
		}else{
			ru = fr(X),rv = fr(Y);
			int ans = (ru == rv);
			if(!ans){
				ans = dfs2(ru,rv);
				for(auto x:temp)
					mark[x] = 0;
				temp.clear();
			}
			castle_answer(ans);
		}
	}
}