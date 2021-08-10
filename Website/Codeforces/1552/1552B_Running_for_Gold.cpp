/*
	Task	: 1552B_Running_for_Gold
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 26 July 2021 [08:40]
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
const int N = 50010;
struct A{
	int id,r[6];
	bool operator < (const A&o) const{
		int cnt = 0;
		rep(i,1,5)
			cnt+=(r[i]<o.r[i]);
		return cnt>=3;
	}
};
A a[N];
void solve(){
	int n;
	cin >> n;
	rep(i,1,n){
		rep(j,1,5)
			cin >> a[i].r[j];
		a[i].id = i;
	}
	sort(a,a+n+1);
	A winner = a[1];
	bool no = false;
	rep(i,2,n){
		if(a[1]<a[i])	continue;
		no = true;
		break;
	}
	if(no)	cout << "-1\n";
	else	cout << a[1].id << '\n';
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int q = 1;
	cin >> q;
	for(int Q=1;Q<=q;Q++){
		// cout << "Case #" << Q << ": ";
		solve();
	}
	return 0;
}