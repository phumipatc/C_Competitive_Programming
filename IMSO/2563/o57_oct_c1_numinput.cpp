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
#define MOD (LL )(9901)
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
int a[1010];
int dp[1010][1010];
vector<PII > v;
void solve(){
	int n,m,now,idx,ans = 1,len,dif;
	for(int i=1;i<=1000;i++)
		for(int j=0;j<=i;j++)
			dp[i][j] = (j == 0 || j == i)?1:(dp[i-1][j]+dp[i-1][j-1])%MOD;
	cin >> n >> m;
	for(int i=1;i<=n;i++)
		cin >> a[i],a[i]+=a[i-1];
	v.push_back({1,1});
	for(int i=1;i<=m;i++){
		cin >> now;
		idx = lower_bound(a+1,a+n+1,now)-a;
		v.push_back({idx,now});
	}
	v.push_back({n,a[n]});
	// for(auto x:v)
	// 	printf("%d %d\n",x.first,x.second);
	for(int i=0;i<v.size()-1;i++){
		len = v[i+1].second-v[i].second-1;
		if(len<=0)	continue;
		dif = v[i+1].first-v[i].first+1;
		ans*=dp[len+1][dif-1];	ans%=MOD;
	}
	cout << ans << '\n';
}
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int q = 1;
	// cin >> q;
	while(q--){
		solve();
	}
	return 0;
}