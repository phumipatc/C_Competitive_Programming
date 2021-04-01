/*
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Algo	:
	Status	: Unfinished [2T in evaluator]
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
	if(b == 0)	return 0;
	if(b == 1)	return a%c;
	LL now = modN(a,b/2);
	if(b&1)	return (((now*now)%c)*(a%c))%c;
	else	return (now*now)%c;
}
int q = 1;
int n,m;
vector<int > shop[120010],cus[120010];
int mark[120010];
int vs[120010],vc[120010];
void initial(){
	cin >> n >> m;
	cin >> q;
	int sq = sqrt(n);
	for(int i=1,num,id;i<=m;i++){
		cin >> num;
		while(num--){
			cin >> id;
			if(num<=sq)	shop[i].push_back(id),mark[i] = 1;
			else		cus[id].push_back(i);
		}
	}
}
void solve(){
	int opr,id,v;
	cin >> opr;
	if(opr ==  1){
		cin >> id >> v;
		if(mark[id]){
			for(auto x:shop[id])
				vc[x]+=v-vs[id];
		}
		vs[id] = v;
	}else{
		cin >> id;
		int ans = vc[id];
		for(auto x:cus[id])
			ans+=vs[x];
		cout << ans << '\n';
	}
}
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	initial();
	for(int Q=1;Q<=q;Q++){
		// cout << "Case #" << Q << ": ";
		solve();
	}
	return 0;
}