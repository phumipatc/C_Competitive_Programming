/*
	Author	: Phumipat C. [MAGCARI] feat. Wasrek, Aphrodicez
	School	: RYW
	Language: C++
	Algo	: BFS
	Status	: Finished
*/
#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define allst(x,y) (x).begin()+y,(x).end()
#define MOD (LL )(1e9+7)
using namespace std;
using LL = long long;
using PII = pair<int ,int >;
using PLL = pair<long long ,long long >;
const int dir4[2][4] = {{1,-1,0,0},{0,0,1,-1}};
const int dir8[2][8] = {{-1,-1,-1,0,1,1,1,0},{-1,0,1,1,-1,0,1,-1}};
const int MAX_INT = 1e9;
const LL MAX_LL = 1e18;
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
LL modN(LL a,LL b,LL c = MOD){
	if(b == 0)	return 0;
	if(b == 1)	return a%c;
	LL now = modN(a,b/2);
	if(b&1)	return (((now*now)%c)*(a%c))%c;
	else	return (now*now)%c;
}
struct A{
	int i,j,w;
};
A now;
queue<A > que;
int mark[22][22];
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int q,h,w,sti,stj,eni,enj,t,m,i,j;
	cin >> q;
	while(q--){
		cin >> h >> w >> sti >> stj >> eni >> enj >> t >> m;
		que.push({sti,stj,0});
		memset(mark,-1,sizeof mark);
		mark[sti][stj] = now.w;
		while(m--){
			cin >> i >> j;
			mark[i][j] = 1e9;
		}
		while(!que.empty()){
			now = que.front();
			que.pop();
			if(now.w == t)	break;
			for(int k=0;k<4;k++){
				int ii = now.i+dir4[0][k];
				int jj = now.j+dir4[1][k];
				if(ii<1 || ii>h || jj<1 || jj>w)	continue;
				if(mark[ii][jj]!=-1)				continue;
				que.push({ii,jj,now.w+1});
				mark[ii][jj] = now.w+1;
			}
		}
		while(!que.empty())	que.pop();
		if(mark[eni][enj]!=-1 && mark[eni][enj]!=1e9)	cout << "Y " << mark[eni][enj] << '\n';
		else											cout << "N 0\n";
	}
	return 0;
}