/*
	Task	: PZ_Deliver
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 16 May 2021 [07:51]
	Algo	: LIS
	Status	: Untest
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
const int N = 200010;
int LIS[N],a[N],b[N];
void solve(){
	int n,cnt = 1;
	multiset<int > ms;
	multiset<int >::iterator it,it2;
	cin >> n;
	rep(i,1,n+1){
		cin >> a[i];
		a[i]-=i;
		if(a[i]<0)	continue;
		ms.insert(a[i]);
	}
	rep(i,1,n+1){
		if(a[i]<0)	continue;
		it = ms.lower_bound(a[i]);
		if(it!=ms.begin()){
			it2 = it,it2--;
			b[cnt++] = *it2;
		}
		b[cnt++] = a[i];
		ms.erase(it);
	}
	int mx = 0;
	rep(i,1,cnt){
		int idx = lower_bound(LIS,LIS+mx,b[i])-LIS;
		if(idx == mx)	mx++;
		LIS[idx] = b[i];
	}
	cout << mx << '\n';
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