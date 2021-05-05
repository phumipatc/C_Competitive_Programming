/*
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Algo	: Implement
	Status	: Finished
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
struct A{
	int h,k,r;
};
A a,b;
void solve(){
	cin >> a.h >> a.k >> a.r >> b.h >> b.k >> b.r;
	int dis = (a.h - b.h) * (a.h - b.h) + (a.k - b.k) * (a.k - b.k);
	int sumr = (a.r + b.r) * (a.r + b.r);
	int mx = max(a.r*a.r,b.r*b.r),mn = min(a.r*a.r,b.r*b.r);
	if(dis>sumr)										cout << "None\n";
	else if(dis == sumr)								cout << "One\n";
	else if(dis>=mx)									cout << "More\n";
	else if((mx + dis - mn) * (mx + dis - mn)>4*mx*dis)	cout << "None\n";
	else if((mx + dis - mn) * (mx + dis - mn)<4*mx*dis)	cout << "More\n";
	else if(dis == 0)									cout << "More\n";
	else												cout << "One\n";
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