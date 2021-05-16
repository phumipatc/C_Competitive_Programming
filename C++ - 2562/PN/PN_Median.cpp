/*
	Task	: PN_Median
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Created	: 06 May 2021 [16:13]
	Algo	: Heap
	Status	: Finished
*/
#include<bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x),end(x)
#define allst(x,y) (x).begin()+y,(x).end()
#define remdup(x) (x).resize(unique((x).begin(),(x).end())-(x).begin())
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
	LL now = modN(a,b/2,c);
	if(b&1)	return (((now*now)%c)*(a%c))%c;
	else	return (now*now)%c;
}
priority_queue<int > l;
priority_queue<int ,vector<int >, greater<int > > r;
void solve(){
	int n,num,temp;
	cin >> n;
	l.push(0),r.push(2e9);
	while(n--){
		cin >> num;
		if(sz(l) == sz(r)){
			if(num>=r.top())	r.push(num),temp = r.top(),r.pop(),l.push(temp);
			else				l.push(num);
			cout << decp(1) << (double )l.top() << '\n';
		}else{
			if(num>=r.top())	r.push(num);
			else				l.push(num),temp = l.top(),l.pop(),r.push(temp);
			cout << decp(1) << (double )(l.top() + r.top())/2 << '\n';
		}
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