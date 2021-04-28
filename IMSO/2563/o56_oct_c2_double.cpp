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
LL minN(vector<LL > a){
	LL minn = 1e18;
	for(auto x:a)
		minn = min(minn,x);
	return minn;
}
LL maxN(vector<LL > a){
	LL maxx = -1e18;
	for(auto x:a)
		maxx = max(maxx,x);
	return maxx;
}
LL modN(LL a,LL b,LL c = MOD){
	if(b == 0)	return 1;
	if(b == 1)	return a%c;
	LL now = modN(a,b/2);
	if(b&1)	return (((now*now)%c)*(a%c))%c;
	else	return (now*now)%c;
}
int qs[100010];
void solve(){
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> qs[i],qs[i]+=qs[i-1];
	for(int i=1;i<n;i++){
		if(qs[i] == qs[n]-qs[i]){
			cout << i << '\n';
			return ;
		}
	}
	for(int i=1;i<n;i++){
		int idx = lower_bound(qs+i+1,qs+n+1,(2*qs[i]+qs[n])/2)-qs;
		if((2*qs[i]+qs[n])%2 == 0 and qs[idx] == (2*qs[i]+qs[n])/2){
			cout << i << ' ' << idx << '\n';
			return ;
		}
	}
	cout << "NO\n";
}
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int q = 1;
	// cin >> q;
	while(q--){
		solve();
	}
	return 0;
}