/*
	Task	: A_Division
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 01 January 2023 [11:01]
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
const int N = 100010;
vector<int > primes;
void genPrimes(){
	vector<bool > isPrime(sqrt(5e6)+5,true);
	isPrime[0] = isPrime[1] = false;
	for(LL i=2;i<=sqrt(5e6);i++){
		if(isPrime[i]){
			primes.push_back(i);
			for(LL j=i*i;j<=sqrt(5e6);j+=i)
				isPrime[j] = false;
		}
	}
}
void init(){
	
}
void solve(){
	genPrimes();
	int n;
	cin >> n;
	map<int ,int > mx,now;
	rep(i,1,n){
		int num;
		cin >> num;
		now.clear();
		for(auto x:primes){
			if(x > num)	break;
			while(num%x == 0){
				now[x]++;
				num/=x;
			}
		}
		if(num > 1)	now[num]++;
		for(auto x:now)
			mx[x.first] = max(mx[x.first],x.second);
	}
	int sum = 0;
	for(auto x:mx)
		sum+=x.second;
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