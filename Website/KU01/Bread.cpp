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
	int w,h,m,n,sx,sy,max1 = 0,max2 = 0;
	cin >> w >> h >> m >> n;
	x.resize(m+2);
	y.resize(n+2);
	for(int i=1;i<=m;i++)
		cin >> x[i];
	x[0] = 0,x[++m] = w;
	for(int i=1;i<=n;i++)
		cin >> y[i];
	y[0] = 0,y[++n] = h;
	sort(x.begin(),x.end());
	sort(y.begin(),y.end());
	for(int i=0;i<x.size()-1;i++){
		sx = x[i+1]-x[i];
		for(int j=0;j<y.size()-1;j++){
			sy = y[j+1]-y[j];
			// printf("%d %d %d\n",sx,sy,sx*sy);
			if(sx*sy>=max1){
				max2 = max1;
				max1 = sx*sy;
			}else if(sx*sy>max2){
				max2 = sx*sy;
			}
		}
	}
	cout << max1 << ' ' << max2 << '\n';
	return 0;
}