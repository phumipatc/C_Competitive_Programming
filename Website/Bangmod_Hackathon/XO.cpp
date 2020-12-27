/*
	Author	: Phumipat C. [MAGCARI] feat. Wasrek, Aphrodicez
	School	: RYW
	Language: C++
	Algo	: Implement
	Status	: Untested
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
int a[3][3],win[2];
PII conv(int now){
	now--;
	return {now/3,now%3};
}
int check(){
	int minn,maxx;

	minn = minN({a[0][0],a[0][1],a[0][2]}),maxx = maxN({a[0][0],a[0][1],a[0][2]});
	if(minn == maxx && maxx!=-1)	return	maxx;

	minn = minN({a[1][0],a[1][1],a[1][2]}),maxx = maxN({a[1][0],a[1][1],a[1][2]});
	if(minn == maxx && maxx!=-1)	return	maxx;

	minn = minN({a[2][0],a[2][1],a[2][2]}),maxx = maxN({a[2][0],a[2][1],a[2][2]});
	if(minn == maxx && maxx!=-1)	return	maxx;

	minn = minN({a[0][0],a[1][0],a[2][0]}),maxx = maxN({a[0][0],a[1][0],a[2][0]});
	if(minn == maxx && maxx!=-1)	return	maxx;

	minn = minN({a[0][1],a[1][1],a[2][1]}),maxx = maxN({a[0][1],a[1][1],a[2][1]});
	if(minn == maxx && maxx!=-1)	return	maxx;

	minn = minN({a[0][2],a[1][2],a[2][2]}),maxx = maxN({a[0][2],a[1][2],a[2][2]});
	if(minn == maxx && maxx!=-1)	return	maxx;

	minn = minN({a[0][0],a[1][1],a[2][2]}),maxx = maxN({a[0][0],a[1][1],a[2][2]});
	if(minn == maxx && maxx!=-1)	return	maxx;

	minn = minN({a[0][2],a[1][1],a[2][0]}),maxx = maxN({a[0][2],a[1][1],a[2][0]});
	if(minn == maxx && maxx!=-1)	return	maxx;

	return -1;
}
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int n,turn = 0,v;
	cin >> n;
	memset(a,-1,sizeof a);
	while(n--){
		cin >> v;
		a[conv(v).first][conv(v).second] = turn;
		turn^=1;
		if(check()!=-1){
			win[check()]++;
			memset(a,-1,sizeof a);
			turn  = 0;
		}
	}
	cout << win[0] << '\n' << win[1] << '\n';
	return 0;
}