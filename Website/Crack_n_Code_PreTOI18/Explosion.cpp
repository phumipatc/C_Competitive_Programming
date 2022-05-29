/*
	Task	: Explosion
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 29 May 2022 [20:06]
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
const int N = 5e5+10;
LL a[N],b[N],mark[N];
void init(){
	
}
void solve(){
	int n,m,x,y;
	LL mx = 0;
	cin >> n >> m >> x >> y;
	rep(i,1,n)
		cin >> a[i],mx = max(mx,a[i]);
	LL l = 1,r = mx/x + 1,mid,cnt,sum;
	while(l<r){
		mid = (l+r)/2,cnt = sum = 0;
		rep(i,1,n)
			b[i] = a[i] - (mid * x);
		fill(mark,mark+N,0);
		rep(i,1,n){
			sum+=mark[i];
			b[i]-=sum;
			if(b[i]<=0)	continue;
			LL temp = (LL )ceil((double ) b[i]/(y-x));
			cnt+=temp;
			mark[i + (2*m) + 1] -= temp * (y-x);
			sum+=temp * (y-x);
		}
		if(cnt>mid)	l = mid+1;
		else		r = mid;
	}
	cout << l << '\n';
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