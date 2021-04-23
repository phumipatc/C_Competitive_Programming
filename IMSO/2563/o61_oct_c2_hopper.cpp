/*
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Algo	: DP [Direct Acyclic Graph]
	Status	: Finished
*/
#include<bits/stdc++.h>
#define all(x) begin(x),end(x)
#define allst(x,y) (x).begin()+y,(x).end()
#define sz(x) (int)(x).size()
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
	if(b == 0)	return 0;
	if(b == 1)	return a%c;
	LL now = modN(a,b/2);
	if(b&1)	return (((now*now)%c)*(a%c))%c;
	else	return (now*now)%c;
}
int a[3010];
int in[3010],dp[3010];
vector<int > g[3010];
int n,m;
int check(int mid){
	memset(in,0,sizeof in);
	memset(dp,-1,sizeof dp);
	queue<int > que;
	int maxx = -1;
	for(int i=0;i<n;i++)
		g[i].clear();
	for(int i=0;i<n;i++)
		for(int j=1;j<=mid;j++)
			if(a[(i+j)%n]>a[i])
				g[i].push_back((i+j)%n),in[(i+j)%n]++;
	for(int i=0;i<n;i++)
		if(!in[i])
			que.push(i),dp[i] = maxx = 0;
	while(!que.empty()){
		int now = que.front();
		que.pop();
		for(auto x:g[now]){
			in[x]--;
			dp[x] = max(dp[x],dp[now]+1);
			maxx = max(maxx,dp[x]);
			if(maxx>=m)	return 1;
			if(!in[x])	que.push(x);
		}
	}
	return 0;
}
void solve(){
	cin >> n >> m;
	for(int i=0;i<n;i++)
		cin >> a[i];
	int l = 1,r = n,mid;
	while(l<r){
		mid = (l+r)/2;
		if(check(mid))	r = mid;
		else			l = mid+1;
	}
	cout << l << '\n';
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int q = 1;
	// cin >> q;
	for(int Q=1;Q<=q;Q++){
		// cout << "Case #" << Q << ": ";
		solve();
	}
	return 0;
}