/*
	Task	: Commando
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 17 May 2021 [13:53]
	Algo	: DP [CHT]
	Status	: Finished
*/
#include<bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i <= (b); ++i)
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
const int N = 1000010;
LL qs[N],dp[N];
int a,b,c;
double cal(int i, int j) {
	return (a * ((qs[j]*qs[j]) - (qs[i]*qs[i])) - b * (qs[j] - qs[i]) + dp[j] - dp[i]) / (a*(qs[j]- qs[i]));
}
LL cost(LL v){
	return (a*v*v) + (b*v) + c;
}
void solve(){
	int n;
	cin >> n >> a >> b >> c;
	fill(dp+1,dp+n+1,(LL )-1e18);
	rep(i,1,n)
		cin >> qs[i],qs[i]+=qs[i-1];
	deque<int > deq;
	deq.push_back(0);
	rep(i,1,n){
		while(sz(deq)>1 && cal(deq[0],deq[1])<2*qs[i])	deq.pop_front();
		dp[i] = dp[deq.front()] + cost(qs[i]-qs[deq.front()]);
		while(sz(deq)>1 && cal(i,deq[sz(deq)-2])<cal(deq[sz(deq)-1],deq[sz(deq)-2]))	deq.pop_back();
		deq.push_back(i);
	}
	cout << dp[n] << '\n';
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