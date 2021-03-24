/*
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Algo	:
	Status	: Unfinished (Change Sol match l r first then each question just bs)
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
	if(b == 0)	return 0;
	if(b == 1)	return a%c;
	LL now = modN(a,b/2);
	if(b&1)	return (((now*now)%c)*(a%c))%c;
	else	return (now*now)%c;
}
#include "rumors.h"
vector<int > l[2010],r[2010];
std::vector<int> analyze_rumors(int N, int K, int Q, std::vector<int> d, std::vector<int> st, std::vector<int> m) {
	// printf("%d %d\n",N,K);
	int w;
	for(int i=0;i<N;i++){
		l[i].push_back(0);
		for(int j=i-1;j>=0;j--){
			w = ceil((double )(d[j+1]-d[j])/K) - 1;
			l[i].push_back(w);
		}
		for(int j=1;j<l[i].size();j++)
			l[i][j]+=l[i][j-1];

		r[i].push_back(0);
		for(int j=i+1;j<N;j++){
			w = ceil((double )(d[j]-d[j-1])/K) - 1;
			r[i].push_back(w);
		}
		for(int j=1;j<r[i].size();j++)
			r[i][j]+=r[i][j-1];
		// for(int j=0;j<r[i].size();j++)
		// 	printf("%d ",r[i][j]);
		// printf("\n");
	}
	vector<int > ans;
	for(int i=0;i<Q;i++){
		int u = st[i];
		ans.push_back(0);
		// printf("start:%d\n",u);
		for(int j=0;j<l[u].size();j++){
			if(l[u][j]>m[i])	break;
			int idx = upper_bound(r[u].begin(),r[u].end(),m[i]-l[u][j])-r[u].begin()-1;
			// printf("%d: %d %d\n",i,j,idx);
			ans.back() = max(ans.back(),j + idx + 1);
		}
	}
	return ans;
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
