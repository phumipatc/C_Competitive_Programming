/*
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Algo	: GD
	Status	: Finished
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int ,int > PII;
typedef pair<long long ,long long > PLL;
vector<PII > sm;
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int q,a,b,n,ans;
	string str;
	cin >> q;
	while(q--){
		cin >> a >> b >> str;
		n = str.length();
		sm.clear();
		for(int i=0;i<n;i++){
			auto x = str[i];
			if(x == '0')	continue;
			if(sm.empty() || sm.back().second!=i-1)	sm.emplace_back(i,i);
			else									sm.back().second++;
		}
		n = sm.size();
		ans = 0;
		// printf("%d\n",n);
		for(int i=0;i<n-1;i++){
			int cost = (sm[i+1].first-sm[i].second-1)*b;
			if(cost<a)	sm[i+1].first = -1,ans+=cost;	//cost + a < 2*a
		}
		for(auto x:sm){
			if(x.first == -1)	continue;
			ans+=a;
		}
		cout << ans << '\n';
	}
	return 0;
}