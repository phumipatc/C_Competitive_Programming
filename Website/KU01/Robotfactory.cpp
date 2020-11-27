/*
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Algo	: Implement
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
	int h1,h2,b1,b2,x,y,sum,maxx = 0;
	cin >> h1 >> h2 >> b1 >> b2 >> x >> y;
	for(int i=0;i<=minN({x,h1,b1});i++)
		for(int j=0;j<=minN({x-i,h2,b2});j++)
			maxx = max(maxx,i + j + min(y,min(h1-i,b2-j) + min(b1-i,h2-j)));
	cout << maxx << '\n';
	return 0;
}