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
	int n,u,v,sum = 0;
	LL ans = 0;
	cin >> n;
	while(n--){
		cin >> u >> v;
		e.push_back({u,1});
		e.push_back({v+1,-1});
	}
	sort(e.begin(),e.end());
	for(int i=0;i<e.size()-1;i++){
		sum+=e[i].second;
		ans+=(LL )(e[i+1].first-e[i].first)*max(0,sum-1);
	}
	cout << ans << '\n';
	return 0;
}