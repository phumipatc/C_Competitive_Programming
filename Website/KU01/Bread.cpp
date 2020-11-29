/*
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Algo	: Sorting
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
vector<int > x,y;
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int w,h,m,n;
	cin >> w >> h >> m >> n;
	x.resize(m+2),x[m+1] = w;
	y.resize(n+2),y[n+1] = h;
	for(int i=1;i<=m;i++)
		cin >> x[i];
	for(int i=1;i<=n;i++)
		cin >> y[i];
	for(int i=0;i<x.size()-1;i++)
		x[i] = x[i+1]-x[i];
	x.pop_back();
	sort(x.begin(),x.end());
	for(int i=0;i<y.size()-1;i++)
		y[i] = y[i+1]-y[i];
	y.pop_back();
	sort(y.begin(),y.end());
	cout << x[m]*y[n] << ' ' << max(x[m-1]*y[n],x[m]*y[n-1]) << '\n';
	return 0;
}