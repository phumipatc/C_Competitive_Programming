/*
	Task	: TOI19_Merge
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 28 May 2023 [19:14]
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
pair<int ,int > a[N],b[N];
void init(){
	
}
void solve(){
	int n,m,q;
	cin >> n >> m >> q;
	rep(i,1,n)
		cin >> a[i].first;
	rep(i,1,n)
		cin >> a[i].second,a[i].second+=a[i-1].second;
	rep(i,1,m)
		cin >> b[i].first;
	rep(i,1,m)
		cin >> b[i].second,b[i].second+=b[i-1].second;

	while(q--){
		int alpha,beta,k;
		cin >> alpha >> beta >> k;
		int l = min(a[1].first,b[1].first*alpha+beta),r = max(a[n].first,b[m].first*alpha + beta),mid,idA,idB;
		while(l<r){
			mid = floor((l+r)/2.0);
			idA = upper_bound(a+1,a+n+1,make_pair(mid,(int )1e9))-a-1;
			idB = upper_bound(b+1,b+m+1,make_pair((mid-beta)/alpha,(int )1e9))-b-1;
			// cerr << l << ' ' << r << " :" << mid << ' ' << idA << ' ' << idB << '\n';
			if(a[idA].second + b[idB].second < k)	l = mid+1;
			else									r = mid;
		}
		cout << l << '\n';
	}
	
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
/*
9 8 1
1 2 3 4 5 6 7 8 10
1 2 1 3 5 7 6 2 1
1 2 4 5 6 7 9 10
1 2 4 6 3 2 2 1
1 0 1
1 0 2
1 0 3
1 0 8
2 -5 1
2 -5 2
2 -5 3
2 -5 8

*/