/*
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Algo	: DP [Recurrence Form]
	Status	: Finished
*/
#include<bits/stdc++.h>
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
PII dp[30];
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int n;
	dp[0] = {1,0};
	for(int i=1;i<=24;i++)
		dp[i] = {dp[i-1].second + dp[i-1].first + 1,dp[i-1].first};
	while(1){
		cin >> n;
		if(n == -1)	break;
		cout << dp[n].first << ' ' << dp[n].first + dp[n].second + 1 << '\n';
	}
	return 0;
}