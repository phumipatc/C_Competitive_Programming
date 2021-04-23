/*
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Algo	:
	Status	:
*/
#include<bits/stdc++.h>
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
	if(b == 0)	return 0;
	if(b == 1)	return a%c;
	LL now = modN(a,b/2);
	if(b&1)	return (((now*now)%c)*(a%c))%c;
	else	return (now*now)%c;
}
vector<int > p,sp;
void solve(){
	int n;
	cin >> n;
	cout << sp[n-1] << '\n';
}
bool mark[2000010];
const int N = 2e6;
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	mark[1] = true;
	for(int i=2;i<=sqrt(N);i++){
		if(mark[i])	continue;
		p.push_back(i);
		for(int j=i*i;j<=N;j+=i)
			mark[j] = true;
	}
	for(int i=sqrt(N)+1;i<=N;i++){
		if(mark[i])	continue;
		p.push_back(i);
	}
	for(int i=0;i<p.size();i++){
		if(mark[i+1])	continue;
		sp.push_back(p[i]);
	}
	int q = 1;
	cin >> q;
	for(int Q=1;Q<=q;Q++){
		// cout << "Case #" << Q << ": ";
		solve();
	}
	return 0;
}