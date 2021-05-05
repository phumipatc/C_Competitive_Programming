/*
	Task	: APIO14_Sequence
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Created	: 05 May 2021 [13:12]
	Algo	: DP [DC Optimization]
	Status	: Unfinished [Runtime Error]
*/
#include<bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < (b); ++i)
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
	if(b == 0)	return 1;
	if(b == 1)	return a%c;
	LL now = modN(a,b/2,c);
	if(b&1)	return (((now*now)%c)*(a%c))%c;
	else	return (now*now)%c;
}
const int N = 100010;
const int K = 205;
LL a[N],dp[2][N];
int div_point[K][N];
void compute(int l,int r,int optl,int optr,int state){
	if(l>r)	return ;
	int mid = (l+r)/2;
	PLL ret = {-1,-1};
	for(int k=optl;k<=optr && k<mid;k++)
		ret = max(ret,{dp[!(state&1)][k] + ((a[mid]-a[k])*a[k]),k});
	dp[state&1][mid] = ret.first,div_point[state][mid] = ret.second;
	compute(l,mid-1,optl,ret.second,state);
	compute(mid+1,r,ret.second,optr,state);
}
void solve(){
	int n,k;
	cin >> n >> k;
	rep(i,1,n+1)
		cin >> a[i],a[i]+=a[i-1];
	rep(i,1,k+1)
		compute(1,n,1,n,i);
	cout << dp[k&1][n] << '\n';
	int pos = n;
	vector<int > ans;
	while(k){
		pos = div_point[k][pos];
		ans.push_back(pos);
		k--;
	}
	reverse(all(ans));
	for(auto x:ans)
		cout << x << ' ';
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