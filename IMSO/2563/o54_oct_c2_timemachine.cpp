/*
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Algo	: Bit-masked Dijkstra
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
int cal(PII a,PII b){
	return (int )ceil(sqrt(((a.first-b.first))*(a.first-b.first) + (a.second-b.second)*(a.second-b.second)));
}
int dis[15][15];
PII pos[12];
int t[12];
int dp[15][2050];
struct A{
	int v,w,state;
	bool operator < (const A&o) const{
		return w>o.w;
	}
};
A now;
priority_queue<A > heap;
void solve(){
	int n,m,k;
	cin >> n >> m >> k;
	for(int i=1;i<=k;i++)
		cin >> pos[i].first >> pos[i].second >> t[i];
	pos[0] = {0,0},pos[k+1] = {n-1,m-1};
	for(int i=0;i<=k+1;i++)
		for(int j=i+1;j<=k+1;j++)
			dis[i][j] = dis[j][i] = cal(pos[i],pos[j]);
	for(int i=0;i<=k+1;i++)
		for(int j=0;j<=2048;j++)
			dp[i][j] = MAX_INT;
	dp[0][0] = 0;
	heap.push({0,0,0});
	int minn = MAX_INT;
	while(!heap.empty()){
		now = heap.top();
		heap.pop();
		if(now.v == k+1)	minn = min(minn,now.w);
		if(now.v>=1 && now.v<=k && !(now.state&(1<<now.v)) && dp[now.v][now.state|(1<<now.v)]>now.w-t[now.v]){
			dp[now.v][now.state|(1<<now.v)] = now.w-t[now.v];
			heap.push({now.v,now.w-t[now.v],now.state|(1<<now.v)});
		}
		for(int i=0;i<=k+1;i++){
			if(i == now.v)	continue;
			if(dp[i][now.state]<=now.w+dis[i][now.v])	continue;
			dp[i][now.state] = now.w+dis[i][now.v];
			heap.push({i,dp[i][now.state],now.state});
		}
	}
	cout << minn << '\n';
}
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int q = 1;
	// cin >> q;
	// initial();
	for(int Q=1;Q<=q;Q++){
		// cout << "Case #" << Q << ": ";
		solve();
	}
	return 0;
}