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
int a[100010];
int dp[100010][5];
vector<int > g[100010];
LL maxx,sum;
void dfs(int now,int p){
	vector<PII > v[5];
	v[0].push_back({a[now],now});
	for(auto x:g[now]){
		if(x == p)	continue;
		dfs(x,now);
		for(int i=1;i<5;i++){
			if(dp[x][i-1] == -1)	continue;
			v[i].push_back({dp[x][i-1],x});
		}
	}
	for(int i=1;i<=4;i++){
		if(v[i].empty())	continue;
		sort(all(v[i]));	reverse(all(v[i]));
	}
	for(int i=0;i<=4;i++){
		if(v[i].empty())	continue;
		dp[now][i] = v[i][0].first;
	}

	if(!v[4].empty())
		maxx = max(maxx,(LL )a[now] + v[4][0].first);

	for(auto x:v[3]){
		if(v[1].empty())	break;
		if(x.second == v[1][0].second)	continue;
		maxx = max(maxx,(LL )v[1][0].first + x.first);
		break;
	}

	for(auto x:v[2]){
		if(x.second == v[2][0].second)	continue;
		maxx = max(maxx,(LL )v[2][0].first + x.first);
	}

	for(auto x:v[1]){
		if(v[3].empty())	break;
		if(x.second == v[3][0].second)	continue;
		maxx = max(maxx,(LL )v[3][0].first + x.first);
	}
}
void solve(){
	int n,u,v;
	cin >> n;
	maxx = -1;
	memset(dp,-1,sizeof dp);
	for(int i=1;i<=n;i++){
		cin >> a[i];
		g[i].clear();
	}
	for(int i=1;i<n;i++){
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1,0);
	cout << maxx << '\n';
}
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int q = 1;
	cin >> q;
	while(q--){
		solve();
	}
	return 0;
}