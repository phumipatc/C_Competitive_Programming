/*
	Author	: Phumipat C. [MAGCARI] feat. Wasrek, Aphrodicez
	School	: RYW
	Language: C++
	Algo	: Binary Tree, DFS
	Status	: Finished
*/
#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define allst(x,y) (x).begin()+y,(x).end()
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
int v[2020],sum[2020];
int n;
void dfs(int u){
	if(u*2<=n)		dfs(u*2);
	if(u*2+1<=n)	dfs(u*2+1);
	if(u!=1 && u*2<=n)	printf("%d %d %d\n",v[u],v[u*2]+v[u*2+1],sum[u]);
}
int main(){
	// ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&v[i]);
	for(int i=n;i>=1;i--)
		sum[i/2]+=sum[i]+v[i];
	dfs(1);
	int u = 1;
	printf("%d %d %d\n",v[u],v[u*2]+v[u*2+1],sum[u]);
	printf("%d\n",sum[1]+v[1]);
	return 0;
}