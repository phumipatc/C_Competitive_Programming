/*
	Task	: Toro_Candy
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 04 December 2021 [22:14]
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
const int M = 2e5+5;
int a[M];
void init(){
	
}
void solve(){
	int n,m;
	LL sum = 0;
	cin >> n >> m;
	rep(i,1,m)
		cin >> a[i],sum+=a[i];
	LL l = 1,r = sum+1,mid;
	int cnt = 0;
	while(l<r){
		mid = (l+r)/2,cnt = 0;
		rep(i,1,m)
			cnt+=ceil((double )a[i]/mid);
		// printf("%lld %d\n",mid,cnt);
		if(cnt>n)	l = mid+1;
		else		r = mid;
	}
	if(r == sum+1)	cout << "-1\n";
	else			cout << l << '\n';
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