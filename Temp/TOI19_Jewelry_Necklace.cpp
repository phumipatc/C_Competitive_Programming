/*
	Task	: TOI19_Jewelry_Necklace
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 31 May 2023 [08:30]
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
const int N = 1000010;
stack<PII > st;
LL dp[N];
char a[N];

void init(){
	
}
void solve(){
	int n;
	cin >> n >> a+1;
	dp[0] = 0;
	rep(i,1,n){
		if(a[i] == 'T'){
			PII val = {i,1};
			if(a[i-1] == 'T'){
				val = st.top();
				st.pop();
				val.first = i;
				val.second++;
			}
			while(!st.empty() && st.top().second < val.second)
				st.pop();
			if(st.empty())	dp[i] = dp[i-1] + i;
			else			dp[i] = dp[i-1] + i - st.top().first + val.second - 1;
			st.push(val);
		}else{
			dp[i] = dp[i-1];
		}
	}
	LL sum = 0;
	rep(i,1,n)
		sum+=dp[i];
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