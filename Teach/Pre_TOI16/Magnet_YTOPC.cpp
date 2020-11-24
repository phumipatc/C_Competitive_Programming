/*
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Algo	: Sweepline
	Status	: Finished
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int ,int > PII;
typedef pair<long long ,long long > PLL;
map<int ,int > mapp;
vector<int > e;
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int n,m,q,u,w,idx;
	cin >> n >> m >> q;
	while(m--){
		cin >> u >> w;
		mapp[u]++;
		mapp[u+w]++;
	}
	e.push_back(1);
	for(auto x:mapp)
		if(x.second%2)
			e.push_back(x.first);
	e.push_back(n+1);
	while(q--){
		cin >> u;
		idx = upper_bound(e.begin(),e.end(),u)-e.begin();
		cout << e[idx]-e[idx-1] << '\n';
	}
	return 0;
}