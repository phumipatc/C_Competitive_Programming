/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int dis[1010][1010];
pair<int ,int > st,en;
pair<int ,int > warp[1010][1010];
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int lv,w,h,b,t,x1,y1,x2,y2;
	cin >> lv;
	while(lv--){
		cin >> w >> h >> st.first >> st.second >> en.first >> en.second >> b >> t;
		for(int i=1;i<=w;i++)
			for(int j=1;j<=h;j++)
				dis[i][j] = 1e9,warp[i][j] = {0,0};
		while(b--){
			cin >> x1 >> y1;
			dis[x1][y1] = 0;
		}
		while(t--){
			cin >> x1 >> y1 >> x2 >> y2;
			warp[x1][y1] = {x2,y2};
		}
	}
	return 0;
}