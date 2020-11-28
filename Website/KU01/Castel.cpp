/*
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Algo	: Math
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
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int n,st,num;
	cin >> n;
	num = 2*(int )sqrt(n-1)-1;
	st = 1 + (num+1)*(num+1)/4;
	cout << (num+1)-((n-st)%2) << '\n';
	return 0;
}