/*
	Task	: SumPrimes
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 13 November 2022 [20:18]
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
void init(){
	
}
vector<int > genPrime(int m,int n){
	vector<int > primes;
	vector<bool > mark(n+10);
	int sq = sqrt(n);
	for(int i=2;i<=sq;i++){
		if(mark[i])	continue;
		for(int j=i*i;j<=n;j+=i)
			mark[j] = true;
	}
	for(int i=m;i<=n;i++){
		if(mark[i])	continue;
		primes.push_back(i);
	}
	return primes;
}
void solve(){
	int a,b,sum = 0;
	cin >> a >> b;
	vector<int > primes = genPrime(a,3*b);
	for(auto x:primes){
		for(int i=a;i<=x/3;i++){
			// use only one i
			if(x-i >= 2*(i+1) && x-i <= 2*b){
				int l = i+1,r = (x-i)/2;
				if((x-i-l) > b){
					int dif = (x-i-l) - b;
					l+=dif;
					if(r<l)	r = l-1;
				}
				sum+=r-l+1;
			}
			// use exactly two i
			if(x-2*i > i && x-2*i <= b)
				sum++;
			// use exactly 3 i
			if(i*3 == x)
				sum++;
			// cout << x << ' ' << i << " : " << sum << '\n';
		}
	}
	cout << sum << '\n';
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
