/*
	Task	: 1552C_Maximize_the_Intersections
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 26 July 2021 [09:27]
	Algo	: 
	Status	: 
*/
#include<bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i <= (b); ++i)
#define repr(i, a, b) for(int i = a; i >= (b); --i)
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
const int N = 110;
bool mark[2*N];
void solve(){
	vector<PII > line;
	vector<int > pnt;
	int n,k,x,y;
	cin >> n >> k;
	rep(i,1,k){
		cin >> x >> y;
		mark[x] = mark[y] = true;
		if(x>y)	swap(x,y);
		line.emplace_back(x,y);
	}
	rep(i,1,2*n){
		if(mark[i])	continue;
		pnt.emplace_back(i);
	}
	rep(i,0,n-k-1)
		line.emplace_back(pnt[i],pnt[i+(n-k)]);
	sort(all(line));
	int cnt = 0;
	rep(i,0,n-1)
		rep(j,i+1,n-1)
			cnt+=(line[i].second>line[j].first && line[i].second<line[j].second);
	cout << cnt << '\n';
	memset(mark,false,sizeof mark);
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