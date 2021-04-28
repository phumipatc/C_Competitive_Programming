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
int a[200010];
set<int > sett;
set<int >::iterator it;
vector<int > ans;
void solve(){
	int n,maxx = 0;
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	ans.clear();
	for(int i=1;i<=n;i++)
		sett.insert(i);
	for(int i=1;i<=n;i++){
		if(maxx<a[i]){
			sett.erase(a[i]);
			ans.push_back(a[i]);
			maxx = a[i];
		}else{
			it = sett.begin();
			ans.push_back(*it);
			sett.erase(it);
		}
	}
	sett.clear();
	for(auto x:ans)
		cout << x << ' ';
	cout << '\n';

	ans.clear();
	maxx = 0;
	for(int i=1;i<=n;i++)
		sett.insert(i);
	for(int i=1;i<=n;i++){
		if(maxx<a[i]){
			sett.erase(a[i]);
			ans.push_back(a[i]);
			maxx = a[i];
		}else{
			it = sett.upper_bound(a[i]-1);
			it--;
			ans.push_back(*it);
			sett.erase(it);
		}
	}
	sett.clear();
	for(auto x:ans)
		cout << x << ' ';
	cout << '\n';
}
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int q = 1;
	cin >> q;
	for(int Q=1;Q<=q;Q++){
		// cout << "Case #" << Q << ": ";
		solve();
	}
	return 0;
}