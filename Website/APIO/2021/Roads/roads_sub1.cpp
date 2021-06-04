/*
	Task	: roads
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 22 May 2021 [15:30]
	Algo	: 
	Status	: 
*/
#include<bits/stdc++.h>
#define FOR(i, a, b) for(int i = a; i <= (b); ++i)
#define ROF(i, a, b) for(int i = a; i >= (b); --i)
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
#include "roads.h"
// #include "grader.cpp"
std::vector<long long> minimum_closure_costs(int N, std::vector<int> U,
                                             std::vector<int> V,
                                             std::vector<int> W) {
	vector<LL > ans;
	for(auto x:W)
		ans.push_back(x);
	sort(all(ans));
	FOR(i,1,sz(ans)-1)
		ans[i]+=ans[i-1];
	reverse(all(ans));
	ans.push_back(0);
	return ans;
}
