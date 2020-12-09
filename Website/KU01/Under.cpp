/*
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Algo	: Sweepline
	Status	: Finished
*/
#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
using namespace std;
using LL = long long;
using PII = pair<int ,int >;
using PLL = pair<long long ,long long >;
const int dir4[2][4] = {{1,-1,0,0},{0,0,1,-1}};
const int dir8[2][8] = {{-1,-1,-1,0,1,1,1,0},{-1,0,1,1,-1,0,1,-1}};
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
vector<PII > e;
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int m,n,u,v,maxx = 0,sum = 0;
	cin >> m >> n;
	for(int i=1;i<=n;i++){
		cin >> u >> v;
		e.push_back({u,1});
		e.push_back({v,-1});
	}
	sort(all(e));
	for(auto x:e){
		sum+=x.second;
		maxx = max(maxx,sum);
	}
	cout << maxx << '\n';
	return 0;
}