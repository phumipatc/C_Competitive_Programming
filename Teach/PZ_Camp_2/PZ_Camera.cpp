/*
	Task	: PZ_Camera
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 18 May 2021 [21:56]
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
const int C = 1e6 + 10;
bool seive[C];
vector<int > p;
void gen_prime(){
	rep(i,2,sqrt(C)){
		if(seive[i])	continue;
		p.push_back(i);
		rep(j,i+i,1e6)
			seive[j] = true;
	}
}
int a[N];
map<int ,int > mapp;
vector<int > v;
int mark[N],dp[N],qs[N];
void solve(){
	gen_prime();
	int n,q,k;
	cin >> n >> q >> k;
	rep(i,1,n){
		cin >> a[i];
		for(auto x:p){
			if(x*x>a[i])		break;
			while(!(a[i]%(x*x)))	a[i]/=(x*x);
		}
		v.push_back(a[i]);
	}
	sort(all(v));	rmdup(v);
	rep(i,1,n)
		a[i] = lower_bound(all(v),a[i])-v.begin();
	int ptr = 1,cnt = 0;
	rep(i,1,n){
		mark[a[i]]++;
		if(mark[a[i]] == 1)	cnt++;
		if(cnt<k)	continue;
		while(cnt>=k){
			mark[a[ptr]]--;
			if(!mark[a[ptr]])	cnt--;
			ptr++;
		}
		ptr--;
		mark[a[ptr]]++;
		if(mark[a[ptr]] == 1)	cnt++;
		dp[i] = ptr;
	}
	rep(i,1,n)
		qs[i] = dp[i]+qs[i-1];
	int l,r;
	while(q--){
		cin >> l >> r;
		ptr = lower_bound(dp+1,dp+n+1,l)-dp;
		if(ptr>r)	cout << "0\n";
		else		cout << (qs[r] - qs[ptr-1]) - (l-1)*(r-ptr+1) << '\n';
	}
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