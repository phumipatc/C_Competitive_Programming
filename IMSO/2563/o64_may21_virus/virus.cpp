/*
	Task	: virus
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 21 May 2021 [13:47]
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
#include "virus.h"
// #include "o64_may21_virus_grader.cpp"
int n, x, y;
int mark[310];
LL dp[310][310];
void initialize(int N, int X, int Y) {
	n = N,x = X,y = Y;
	vector<int > v;
	rep(i,1,n)
		v.push_back(i);
	if(N<=11){
		do{
			if(v.front()!=X || v.back()!=Y)	continue;
			int cnt = 0;
			rep(i,1,n-2){
				if(v[i]>v[i-1] && v[i]>v[i+1])		cnt++;
				else if(v[i]<v[i-1] && v[i]<v[i+1])	cnt++;
			}
			mark[cnt]++;
		}while(next_permutation(all(v)));
	}
	rep(i,1,300)
		dp[i][0] = 1;
	rep(j,1,300)
		rep(i,1,300)
			dp[i][j] = (dp[i][j-1]*(LL )i)%MOD;
}

int ask(int L) {
	if(n<=11)									return mark[L];
	if((x == 1 && y == n) || (x!=1 && y!=n))	return 0;
	if(x == 1)									return dp[2][n-y-1];
	if(y == n)									return dp[2][x-2];
	return 0;
}