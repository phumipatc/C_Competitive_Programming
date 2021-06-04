/*
	Task	: train
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 26 May 2021 [13:32]
	Algo	: DP + Lazy Segment Tree
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
#include "train.h"
const int mxN = 200010;
int tree[4*mxN];
PII lazy[4*mxN];
void build(int l,int r,int now){
	if(l == r){
		tree[now] = 1e9;
		return ;
	}
	int mid = (l+r)/2;
	build(l,mid,now*2),build(mid+1,r,now*2+1);
	tree[now] = 1e9;
}
void upd(int l,int r,int now,int ll,int rr,int v){
	if(lazy[now].first){
		tree[now] = min(tree[now],lazy[now].second);
		if(l!=r){
			if(lazy[now*2].first)	lazy[now*2].second = min(lazy[now*2].second,lazy[now].second);
			else					lazy[now*2] = {1,lazy[now].second};
			if(lazy[now*2+1].first)	lazy[now*2+1].second = min(lazy[now*2+1].second,lazy[now].second);
			else					lazy[now*2+1] = {1,lazy[now].second};
		}
		lazy[now] = {0,1e9};
	}
	if(r<ll || l>rr)	return ;
	if(ll<=l && r<=rr){
		tree[now] = min(tree[now],v);
		if(l!=r){
			if(lazy[now*2].first)	lazy[now*2].second = min(lazy[now*2].second,v);
			else					lazy[now*2] = {1,v};
			if(lazy[now*2+1].first)	lazy[now*2+1].second = min(lazy[now*2+1].second,v);
			else					lazy[now*2+1] = {1,v};
		}
		return ;
	}
	int mid = (l+r)/2;
	upd(l,mid,now*2,ll,rr,v),upd(mid+1,r,now*2+1,ll,rr,v);
	tree[now] = min(tree[now*2],tree[now*2+1]);
}
int read(int l,int r,int now,int ll,int rr){
	if(lazy[now].first){
		tree[now] = min(tree[now],lazy[now].second);
		if(l!=r){
			if(lazy[now*2].first)	lazy[now*2].second = min(lazy[now*2].second,lazy[now].second);
			else					lazy[now*2] = {1,lazy[now].second};
			if(lazy[now*2+1].first)	lazy[now*2+1].second = min(lazy[now*2+1].second,lazy[now].second);
			else					lazy[now*2+1] = {1,lazy[now].second};
		}
		lazy[now] = {0,1e9};
	}
	if(r<ll || l>rr)	return 1e9;
	if(ll<=l && r<=rr)	return tree[now];
	int mid = (l+r)/2;
	return min(read(l,mid,now*2,ll,rr),read(mid+1,r,now*2+1,ll,rr));
}
int find_min_cost(int N, int M,
		  std::vector<int>& s,
		  std::vector<int>& t,
		  std::vector<int>& c)
{
	build(0,N,1);
	upd(0,N,1,0,0,0);
	rep(i,0,M-1){
		int mn = read(0,N,1,s[i],t[i]);
		// printf("%d:%d\n",i,mn);
		upd(0,N,1,s[i],t[i],mn+c[i]);
	}
	int ans = read(0,N,1,N-1,N-1);
	if(ans == 1e9)	return -1;
	else			return ans;
}
/*
7 7
0 2 10
1 3 50
2 6 200
2 4 30
4 6 200
3 6 10
0 6 1000
*/