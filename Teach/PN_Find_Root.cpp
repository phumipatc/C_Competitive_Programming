/*
	Task	: PN_Find_Root
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 13 May 2021 [09:37]
	Algo	: Matrix Exponentiation
	Status	: Finished
*/
#include<bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < (b); ++i)
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
int K;
struct A{
	int a[4][4];
	A operator * (const A&o) const{
		A ret;
		rep(i,0,4){
			rep(j,0,4){
				ret.a[i][j] = 0;
				rep(k,0,4)
					ret.a[i][j]+=a[i][k]*o.a[k][j],ret.a[i][j]%=K;
			}
		}
		return ret;
	}
}p[31];
void solve(){
	int a,b,c,n;
	cin >> a >> b >> c >> n >> K;
	p[0] = {a,2*b,3*c,0,b,a,0,3*c,c,0,a,2*b,0,c,b,a};
	rep(i,1,31)	p[i] = p[i-1] * p[i-1];
	A now = {1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1};
	rep(i,0,31){
		if(!(n&(1<<i)))	continue;
		now = p[i] * now;
	}
	rep(i,0,4)
		cout << now.a[i][0] << ' ';
	cout << '\n';
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