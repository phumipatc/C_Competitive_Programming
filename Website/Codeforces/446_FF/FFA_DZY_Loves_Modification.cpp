/*
	Task	: FFA_DZY_Loves_Modification
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 25 July 2021 [14:46]
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
const int N = 3010;
const int K = 1000010;
int sumr[N],sumc[N];
LL maxr[K],maxc[K];
void solve(){
	int n,m,k,d,num;
	cin >> n >> m >> k >> d;
	memset(sumr,0,sizeof sumr);
	memset(sumc,0,sizeof sumc);
	rep(i,1,n){
		rep(j,1,m){
			cin >> num;
			sumr[i]+=num,sumc[j]+=num;
		}
	}
	priority_queue<LL > r,c;
	rep(i,1,n)	r.push(sumr[i]);
	rep(i,1,m)	c.push(sumc[i]);
	rep(i,1,k){
		LL now = r.top();
		r.pop();
		maxr[i] = maxr[i-1] + now;
		r.push(now-m*d);
 
		now = c.top();
		c.pop();
		maxc[i] = maxc[i-1] + now;
		c.push(now-n*d);
	}
	LL ans = -1e18;
	rep(i,0,k)
		ans = max(ans,maxr[i] + maxc[k-i] - (LL )i*(k-i)*d);
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