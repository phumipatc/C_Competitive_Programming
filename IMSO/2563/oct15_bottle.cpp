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
#define nl now*2
#define nr now*2+1
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
	int v,id;
	bool operator < (const A&o) const{
		return v<o.v;
	}
};
priority_queue<A > heap;
int mark[100010];
void solve(){
	int n,m,num,cnt;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> num;
		heap.push({num,i});
	}
	mark[0] = mark[n+1] = 1;
	while(m--){
		cin >> num;
		cnt = 0;
		vector<int > v;
		while(!heap.empty() && heap.top().v>num){
			auto now = heap.top();
			heap.pop();
			if(mark[now.id])	continue;
			mark[now.id] = 1;
			cnt++;
			v.push_back(now.id-1);
			v.push_back(now.id+1);
		}
		for(auto x:v){
			if(mark[x])	continue;
			mark[x]++;
			cnt++;
		}
		cout << cnt << '\n';
	}
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