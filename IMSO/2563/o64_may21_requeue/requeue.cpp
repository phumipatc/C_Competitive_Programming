/*
	Task	: requeue
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 21 May 2021 [14:39]
	Algo	: LIS + Observe
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
int dp[2500010],LIS[2500010];
int requeue(std::vector<int> Q, int k){

	dp[1] = 0;
	rep(i,2,sz(Q))	dp[i] = dp[(int )ceil((double )i/k)]+1;

	int mx = 0;
	for(auto x:Q){
		int idx = lower_bound(LIS,LIS+mx,x)-LIS;
		if(idx == mx)	mx++;
		LIS[idx] = x;
	}
	return dp[mx];
}