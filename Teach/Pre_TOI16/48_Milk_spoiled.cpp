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
vector<PII > e;
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int q,n,x,y,z,sum,l,r,maxx;
	cin >> q;
	while(q--){
		cin >> n >> x >> y >> z;
		maxx = sum = x*n;
		e.clear();
		for(int i=1;i<=n;i++){
			cin >> l >> r;
			e.push_back({l,y-x});
			e.push_back({r+1,z-y});
		}
		sort(e.begin(),e.end());
		for(auto x:e){
			sum+=x.second;
			maxx = max(maxx,sum);
		}
		cout << maxx << '\n';
	}
	return 0;
}