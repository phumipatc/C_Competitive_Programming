/*
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Algo	:
	Status	: 
*/
#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define allst(x,y) (x).begin()+y,(x).end()
#define decp(x) fixed << setprecision(x)
#define MOD (LL )(1e9+7)
using namespace std;
using LL = long long;
using PII = pair<int ,int >;
using PLL = pair<long long ,long long >;
const int dir4[2][4] = {{1,-1,0,0},{0,0,1,-1}};
const int dir8[2][8] = {{-1,-1,-1,0,1,1,1,0},{-1,0,1,1,-1,0,1,-1}};
const int MAX_INT = 1e9;
const LL MAX_LL = 1e18;
LL modN(LL a,LL b,LL c = MOD){
	if(b == 0)	return 1;
	if(b == 1)	return a%c;
	LL now = modN(a,b/2);
	if(b&1)	return (((now*now)%c)*(a%c))%c;
	else	return (now*now)%c;
}
#include "rumors.h"
vector<int > l[2010],r[2010];
std::vector<int> analyze_rumors(int N, int K, int Q, std::vector<int> d, std::vector<int> st, std::vector<int> m) {
	
}

//grader
int main(){
	freopen("sample.in","r",stdin);
	int N, K, Q;
	std::vector<int> d;
	scanf("%d%d%d",&N,&K,&Q);
	assert(1 <= N && N <= 2000);
	assert(1 <= K && K <= 100000);
	assert(1 <= Q && Q <= 800000);
	for(int i = 0; i < N; i++){
		int x;
		scanf("%d", &x);
		d.push_back(x);
		assert(x <= 9999999);
		if(i > 0) assert(d[i-1] < d[i]);
	}
	std::vector<int> qx, qj;
	for(int i = 0; i < Q; i++){
		int x, j;
		scanf("%d%d",&x,&j);
		assert(0 <= x && x < N);
		assert(0 <= j && j <= 9999999);
		qx.push_back(x);
		qj.push_back(j);
	}
	std::vector<int> answers = analyze_rumors(N, K, Q, d, qx, qj);
	for(int ans : answers){
		printf("%d\n", ans);
	}
	return 0;
}
