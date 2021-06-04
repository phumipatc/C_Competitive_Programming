/*
	Task	: reach
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 26 May 2021 [14:03]
	Algo	: Segment Tree
	Status	: Finished
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
#include "reach.h"
const int mxN = 100010;
int tree[4*mxN];
void build(int l,int r,int now){
	if(l == r){
		tree[now] = 1e9;
		return ;
	}
	int mid = (l+r)/2;
	build(l,mid,now*2),build(mid+1,r,now*2+1);
	tree[now] = 1e9;
}
void upd(int l,int r,int now,int idx,int v){
	if(l == r){
		tree[now] = min(tree[now],v);
		return ;
	}
	int mid = (l+r)/2;
	if(idx<=mid)	upd(l,mid,now*2,idx,v);
	else			upd(mid+1,r,now*2+1,idx,v);
	tree[now] = min(tree[now*2],tree[now*2+1]);
}
int read(int l,int r,int now,int ll,int rr){
	if(r<ll || l>rr)	return 1e9;
	if(ll<=l && r<=rr)	return tree[now];
	int mid = (l+r)/2;
	return min(read(l,mid,now*2,ll,rr),read(mid+1,r,now*2+1,ll,rr));
}
int n;
void initialize(int N) {
	n = N;
	build(0,N,1);
}

void add_arc(int u, int v) {
	upd(0,n,1,v,u);
}

bool is_reachable(int u, int v, int t) {
	if(t<u)	return true;
	if(t<v)	return false;
	int ret = read(0,n,1,v+1,t);
	if(ret>=u)	return false;
	else		return true;
}