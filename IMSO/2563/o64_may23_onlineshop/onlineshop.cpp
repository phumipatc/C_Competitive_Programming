/*
	Task	: onlineshop
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 23 May 2021 [14:28]
	Algo	: 
	Status	: 94 pt
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
#include "onlineshop.h"
const int mxN = 1000000;
int cnt[(mxN/1009)+10];
void sell_all(int N)
{
	// Training
	int p = mxN-1000;
	rep(i,1,N/50){
		bool ret = sell_price((p/2+1000));
		if(ret){
			cnt[p/(2*1009)]++;
			if(p+(p/2)<=mxN+mxN*3/2)	p+=p/2;
		}else{
			p = 3*p/4;
		}
	}
	int mx = -1,sell;
	rep(i,0,(mxN/1009)+5){
		if(cnt[i]>mx){
			mx = cnt[i];
			sell = (i*1009)+1000;
		}
	}
	// Testing
	rep(i,N/50+1,N)
		sell_price(sell);
}