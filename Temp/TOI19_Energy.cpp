/*
	Task	: TOI19_Energy
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 29 May 2023 [10:58]
	Algo	: 
	Status	: 
*/
#include<bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i <= (b); ++i)
#define repr(i, a, b) for(int i = a; i >= (b); --i)
#define repl(i, a, b) for(LL i = a; i <= (b); ++i)
#define reprl(i, a, b) for(LL i = a; i >= (b); --i)
#define all(x) begin(x),end(x)
#define allst(x,y) (x).begin()+y,(x).end()
#define rmdup(x) sort(all(x)),(x).resize(unique((x).begin(),(x).end())-(x).begin())
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
const int N = 310;
int qs[N],d;
LL dp[N][N][10];
LL recurse(int l,int r,int layer){
	if(!layer)				return 1;
	if(l == r)				return 0;
	if(dp[l][r][layer]!=-1)	return dp[l][r][layer];
	LL ret = 0;
	rep(k,l,r-1){
		int lval = qs[k] - qs[l-1];
		int rval = qs[r] - qs[k];
		// cerr << l << ' ' << r << ' ' << layer << ' ' << k << '\n';
		if(abs(lval-rval)<=d){
			int lret = recurse(l,k,layer-1);
			if(!lret)	continue;
			ret = (ret+((lret*recurse(k+1,r,layer-1))%MOD))%MOD;
		}
	}
	return dp[l][r][layer] = ret;
}
void init(){
	
}
void solve(){
	int n,k;
	cin >> n >> k >> d;
	rep(i,1,n)
		cin >> qs[i],qs[i]+=qs[i-1];
	memset(dp,-1,sizeof dp);
	cout << recurse(1,n,k-1) << '\n';
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	// freopen("d:/Code/C_Programming/input.in","r",stdin);
	init();
	int q = 1;
	// cin >> q;
	for(int Q=1;Q<=q;Q++){
		// cout << "Case #" << Q << ": ";
		solve();
	}
	return 0;
}