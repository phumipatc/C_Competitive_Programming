/*
	Task	: ToroGifting
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 31 December 2021 [18:56]
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
const int N = 510;
int a[N][N],qs[N][N];
void init(){
	
}
void solve(){
	int n,m;
	cin >> n >> m;
	rep(i,1,n)
		rep(j,1,m)
			cin >> a[i][j];
	rep(i,1,n)
		rep(j,1,m)
			qs[i][j] = a[i][j] + qs[i][j-1];
	int mx = -1e9;
	rep(i,1,m){
		rep(j,i,m){
			int sum = 0;
			rep(k,1,n){
				sum+=qs[k][j] - qs[k][i-1];
				mx = max(mx,sum);
				if(sum<0)	sum = 0;
			}
		}
	}
	cout << mx << '\n';
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