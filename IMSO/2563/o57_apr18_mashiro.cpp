/*
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Algo	:
	Status	:
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
	LL now = modN(a,b/2);
	if(b&1)	return (((now*now)%c)*(a%c))%c;
	else	return (now*now)%c;
}
int n,m;
bool sieve[2000010];
vector<int > prime;
int decomp(int a,int b){
	int ret=0;
	for(LL i=b;i<=a;i*=b)
		ret+=a/i;
	return ret;
}
void solve(){
	cin >> n >> m;
	for(int i=2;i<=2*n;i++)
		sieve[i] = true;
	for(int i=2;i<=2*n;i++){
		if(!sieve[i])	continue;
		prime.emplace_back(i);
		for(int j=i+i;j<=2*n;j+=i)
			sieve[j] = false;
	}
	LL ans = 1;
	for(auto x:prime)
		ans*=modN(x,decomp(2*n,x) - decomp(n,x)*2,m),ans%=m;
	cout << (ans*ans)%m;
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