/*
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Algo	: MO's algorithm
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
	if(b == 0)	return 0;
	if(b == 1)	return a%c;
	LL now = modN(a,b/2);
	if(b&1)	return (((now*now)%c)*(a%c))%c;
	else	return (now*now)%c;
}
struct A{
	int st,en,id;
	bool operator < (const A&o) const{
		return en<o.en;
	}
};
vector<A > cluster[230];
vector<int > ans;
int a[50010],mark[50010];
map<int ,int > mapp;
void solve(){
	int n,m,u,v,sq,cnt = 1;
	cin >> n;
	sq = sqrt(n);
	for(int i=0;i<n;i++){
		cin >> a[i];
		if(mapp[a[i]]){
			a[i] = mapp[a[i]];
			continue;
		}
		mapp[a[i]] = cnt;
		a[i] = cnt++;
	}
	cin >> m;
	ans.resize(m);
	for(int i=0;i<m;i++){
		cin >> u >> v;
		cluster[u/sq].push_back({u,v,i});
	}
	for(int i=0;i<=224;i++){
		if(cluster[i].empty())	continue;
		sort(all(cluster[i]));
		int st = cluster[i][0].st,en = cluster[i][0].st,cnt = 0;
		memset(mark,0,sizeof mark);
		mark[a[st]]++;
		for(auto x:cluster[i]){
			while(st<x.st){
				mark[a[st]]--;
				cnt-=(mark[a[st]]>=1);
				st++;
			}
			while(st>x.st){
				st--;
				mark[a[st]]++;
				cnt+=(mark[a[st]]>=2);
			}
			while(en<x.en){
				en++;
				mark[a[en]]++;
				cnt+=(mark[a[en]]>=2);
			}
			ans[x.id] = cnt;
		}
	}
	for(auto x:ans)
		cout << x << '\n';
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