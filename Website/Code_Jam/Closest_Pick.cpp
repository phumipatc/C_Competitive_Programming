/*
	Task	: Closest_Pick
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Created	: 01 May 2021 [19:00]
	Algo	: Greedy
	Status	: Finished
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
	LL now = modN(a,b/2,c);
	if(b&1)	return (((now*now)%c)*(a%c))%c;
	else	return (now*now)%c;
}
void solve(){
	int n,k;
	vector<int > a;
	cin >> n >> k;
	a.resize(n);
	rep(i,0,n)
		cin >> a[i];
	sort(all(a)),a.resize(unique(all(a))-a.begin());
	int ans = max(a.front()-1,k-a.back());
	vector<int > b;
	rep(i,0,sz(a)-1){
		b.push_back((a[i+1]-a[i])/2);
		ans = max(ans,a[i+1]-a[i]-1);
	}
	b.push_back(a[0]-1),b.push_back(k-a.back());
	sort(all(b),greater<int >());
	cout << (double )max(ans,b[0]+b[1])/k << '\n';
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int q = 1;
	cin >> q;
	for(int Q=1;Q<=q;Q++){
		cout << "Case #" << Q << ": ";
		solve();
	}
	return 0;
}