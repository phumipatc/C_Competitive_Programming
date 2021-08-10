/*
	Task	: FFA_DZY_Loves_Sequences
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 24 July 2021 [12:57]
	Algo	: 
	Status	: 
*/
#include<bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i <= (b); ++i)
#define repr(i, a, b) for(int i = a; i >= (b); --i)
#define all(x) begin(x),end(x)
#define allst(x,y) (x).begin()+y,(x).end()
#define rmdup(x) (x).resize(unique((x).begin(),(x).end())-(x).begin())
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
const int N = 100010;
int l[N],r[N],a[N];
void solve(){
	int n;
	cin >> n;
	rep(i,1,n)
		cin >> a[i];
	rep(i,1,n)
		l[i] = (a[i]>a[i-1]?l[i-1]:0)+1;
	repr(i,n,1)
		r[i] = (a[i]<a[i+1]?r[i+1]:0)+1;
	int ans = 0;
	rep(i,1,n){
		ans = max({ans,l[i-1]+1,r[i+1]+1});
		if(a[i-1]<a[i+1]-1)	ans = max(ans,l[i-1]+1+r[i+1]);
		// printf("%d\n",ans);
	}
	cout << ans << '\n';
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