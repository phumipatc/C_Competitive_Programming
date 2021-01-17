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
#define remdup(x) (x).resize(unique((x).begin(),(x).end())-(x).begin())
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
	if(b == 0)	return 0;
	if(b == 1)	return a%c;
	LL now = modN(a,b/2);
	if(b&1)	return (((now*now)%c)*(a%c))%c;
	else	return (now*now)%c;
}
int tree[100010];
vector<int > a,b;
map<int ,int > mapp;
void upd(int idx,int v){
	while(idx<=100003){
		tree[idx]+=v;
		idx += idx & -idx;
	}
}
int qr(int idx,int sum = 0){
	while(idx>0){
		sum+=tree[idx];
		idx -= idx & -idx;
	}
	return sum;
}
void solve(){
	int n;
	LL sum = 0;
	cin >> n;
	a.resize(n);
	for(int i=0;i<n;i++)
		cin >> a[i];
	b = a;
	sort(all(b));
	remdup(b);
	for(int i=0;i<b.size();i++)
		mapp[b[i]] = i+1;
	for(int i=n-1;i>=0;i--){
		upd(mapp[a[i]],1);
		sum+=qr(mapp[a[i]]-1);
	}
	cout << sum << '\n';
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