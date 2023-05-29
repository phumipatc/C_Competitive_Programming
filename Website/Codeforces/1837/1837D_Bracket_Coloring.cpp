/*
	Task	: 1837D_Bracket_Coloring
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 25 May 2023 [23:17]
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
const int N = 2e5+10;
char str[N];
int color[N];
void init(){
	
}
void solve(){
	int n,c = 0;
	cin >> n >> str+1;
	set<int > close,open;
	rep(i,1,n){
		if(str[i] == '(')
			open.insert(i);
		else
			close.insert(i);
	}
	if(open.size () != close.size()){
		cout << "-1\n";
		return ;
	}
	while(!open.empty()){
		auto x = open.begin();
		auto idx = close.lower_bound(*x);
		if(idx == close.end())
			break;
		c = 1;
		color[*x] = color[*idx] = c;
		// cerr << *x << " pair with " << *idx << '\n';
		close.erase(idx);
		open.erase(x);
	}
	if(!open.empty() && !close.empty()){
		c++;
		while(!close.empty()){
			auto x = close.begin();
			auto idx = open.lower_bound(*x);
			if(idx == open.end())
				break;
			color[*x] = color[*idx] = c;
			open.erase(idx);
			close.erase(x);
		}
	}
	if(!open.empty() || !close.empty()){
		cout << "-1\n";
		return ;
	}
	cout << c << '\n';
	rep(i,1,n)
		cout << color[i] << ' ';
	cout << '\n';
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	// freopen("d:/Code/C_Programming/input.in","r",stdin);
	init();
	int q = 1;
	cin >> q;
	for(int Q=1;Q<=q;Q++){
		// cout << "Case #" << Q << ": ";
		solve();
	}
	return 0;
}