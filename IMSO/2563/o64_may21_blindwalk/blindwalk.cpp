/*
	Task	: blindwalk
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 21 May 2021 [14:59]
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
#include "blindwalk.h"
// #include "o64_may21_blindwalk_grader.cpp"
const LL FOOT = 2596418101;
const LL BTS = 840634349;
const LL MRT = 590846489;
LL dis[530][530];
int cnt[530];
vector<vector<int>> build_graph(int N)
{
	vector<vector<int > > ans;
	rep(i,1,N){
		rep(j,i+1,N){
			if(cnt[j] == 2)	continue;
			if(cnt[i] == 2)	break;
			dis[i][j] = ask(i,j);
			if(dis[i][j] == FOOT || dis[i][j] == BTS || dis[i][j] == MRT)	cnt[i]++,cnt[j]++;
		}
	}
	return ans;
}
