/*
	Author	: Phumipat C. [MAGCARI] feat. Wasrek, Aphrodicez
	School	: RYW
	Language: C++
	Algo	: Heap
	Status	: Untested
*/
#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define allst(x,y) (x).begin()+y,(x).end()
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
priority_queue<int > heap;
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int m,n,v;
	LL sum = 0;
	cin >> m >> n;
	for(int i=1;i<=m;i++){
		cin >> v;
		heap.push(v);
	}
	for(int i=1;i<=n;i++){
		auto now = heap.top();
		heap.pop();
		sum+=((i%3)?now:now/2);
		if(now!=1)	heap.push(now-1);
	}
	cout << sum << '\n';
	return 0;
}