/*
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Algo	: DP, Binary Search
	Status	: Finished
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
LL minN(vector<LL > a){
	LL minn = 1e18;
	for(auto x:a)
		minn = min(minn,x);
	return minn;
}
LL maxN(vector<LL > a){
	LL maxx = -1e18;
	for(auto x:a)
		maxx = max(maxx,x);
	return maxx;
}
LL modN(LL a,LL b,LL c = MOD){
	if(b == 0)	return 1;
	if(b == 1)	return a%c;
	LL now = modN(a,b/2);
	if(b&1)	return (((now*now)%c)*(a%c))%c;
	else	return (now*now)%c;
}
#include "obstacle.h"
vector<PII > bs[100010];
int n,m;
void initialize(int N, int M, int Q,
		std::vector<std::vector<int>>& rowlen,
		std::vector<std::vector<int>>& collen)
{
	n = N,m = M;

	int lr[N+5][M+5],ud[N+5][M+5];
	for(int i=0;i<N;i++)
		for(int j=0;j<M-1;j++)
			lr[i][j] = rowlen[i][j];
	for(int i=0;i<N-1;i++)
		for(int j=0;j<M;j++)
			ud[i][j] = collen[i][j];

	int dp[N+5][M+5],dprv[N+5][M+5];
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
			dp[i][j] = dprv[i][j] = 2e9;

	dp[0][0] = 0;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			dp[i+1][j] = min(dp[i+1][j],dp[i][j] + ud[i][j]);
			dp[i][j+1] = min(dp[i][j+1],dp[i][j] + lr[i][j]);
		}
	}
	dprv[N-1][M-1] = 0;
	for(int i=N-1;i>=0;i--){
		for(int j=M-1;j>=0;j--){
			if(i!=N-1)	dprv[i][j] = min(dprv[i][j],dprv[i+1][j] + ud[i][j]);
			if(j!=M-1)	dprv[i][j] = min(dprv[i][j],dprv[i][j+1] + lr[i][j]);
		}
	}

	// for(int i=0;i<N;i++){
	// 	for(int j=0;j<M;j++){
	// 		printf("%d ",dp[i][j]);
	// 	}
	// 	printf("\n");
	// }

	for(int j=0;j<M;j++){
		bs[j].resize(N);
		for(int i=0;i<N;i++)
			bs[j][i] = {dp[i][j] + dprv[i][j],-i};
		sort(all(bs[j]));
		for(int i=0;i<N;i++)
			bs[j][i].second = max(bs[j][i].second*(-1),bs[j][max(0,i-1)].second);
	}
}

int ask(int r, int c)
{
	if(c == 0 && r>=0)	return -1;
	c--,r++;
	int ll = 0,rr = n,mid;
	while(ll<rr){
		mid = (ll+rr)/2;
		if(bs[c][mid].second>=r)	rr = mid;
		else						ll = mid+1;
	}

	// for(int i=0;i<n;i++)
	// 	printf("%d %d\n",bs[c][i].first,bs[c][i].second);

	if(ll == n)	return -1;
	return bs[c][ll].first;

}

//grader
int main() {
	int N, M, Q;
	scanf("%d %d %d", &N, &M, &Q);
	vector<vector<int>> rowlen(N, vector<int>(M-1));
	vector<vector<int>> collen(N-1, vector<int>(M));
	for (auto &vec : rowlen)
		for (auto &v : vec)
			scanf("%d", &v);
	for (auto &vec : collen)
		for (auto &v : vec)
			scanf("%d", &v);
	vector<pair<int, int>> query;
	for (int i = 0; i < Q; ++i) {
		int r, c; scanf("%d %d", &r, &c);
		query.emplace_back(r, c);
	}
	initialize(N, M, Q, rowlen, collen);
	for (auto x : query) {
		printf("%d\n", ask(x.first, x.second));
	}
}
/*
3 5 2
1 1 7 8
1 1 3 6
9 4 1 1
4 3 1 2 4
6 2 2 3 8
0 4
1 2

*/