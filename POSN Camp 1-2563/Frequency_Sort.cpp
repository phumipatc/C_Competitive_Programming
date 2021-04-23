/*
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Algo	:
	Status	:
*/
#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define allst(x,y) (x).begin()+y,(x).end()
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
struct A{
	int v,freq,pos;
	bool operator < (const A&o) const{
		if(freq!=o.freq)	return freq>o.freq;
		else				return pos<o.pos;
	}
};
int a[1010];
vector<A > ans;
void solve(){
	int n,c;
	cin >> n >> c;
	for(int i=0;i<n;i++)
		cin >> a[i];
	for(int i=0;i<n;i++){
		int ch = 0;
		for(auto x:ans){
			if(x.v == a[i]){
				ch = 1;
				break;
			}
		}
		if(ch)	continue;
		int cnt = 0;
		for(int j=i;j<n;j++)
			cnt+=(a[i] == a[j]);
		ans.push_back({a[i],cnt,i});
	}
	sort(all(ans));
	for(auto x:ans){
		for(int i=1;i<=x.freq;i++)
			cout << x.v << ' ';
	}
}
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int q = 1;
	// cin >> q;
	for(int Q=1;Q<=q;Q++){
		// cout << "Case #" << Q << ": ";
		solve();
	}
	return 0;
}