/*
	Task	: dual
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 25 May 2021 [14:51]
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
#include "dual.h"
const int N = 1e7+10;
struct A{
	int cost,cap,pos;
	bool operator < (const A&o) const{
		if(cost!=o.cost)	return cost>o.cost;
		else				return pos>o.pos;
	}
}now;
priority_queue<A > heap;
int tree[N];
void upd(int idx,int v){
	for(;idx<=1e7+3;idx+=(idx&-idx))
		tree[idx]+=v;
}
int read(int idx,int sum = 0){
	for(;idx;idx-=(idx&-idx))
		sum+=tree[idx];
	return sum;
}
LL minimum(int n,int v,vector<int > &a){
	while(!heap.empty())	heap.pop();
	memset(tree,0,sizeof tree);
	int cut = 0,temp = 0;
	LL ret = 0;
	rep(i,1,n){
		heap.push({a[i-1],v,i});
		while(!heap.empty()){
			now = heap.top();
			heap.pop();
			if(now.pos<=cut)	continue;
			ret+=now.cost;
			upd(now.pos,1);
			upd(i+1,-1);
			temp = max(temp,(int )now.pos);
			if(read(temp) == v)	cut = temp;
			now.cap--;
			if(now.cap>0)	heap.push(now);
			break;
		}
	}
	return ret;
}
long long dual_fuel(int n,int v,vector<int> &a, vector<int> &b) {
	return minimum(n,v,a) + minimum(n,v,b);
}
/*
4 2
3 1 1 4
1 5 1 6
*/