/*
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Algo	: Divide & Conquer
	Status	: Unfinished [X for all cases]
*/
#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define allst(x,y) (x).begin()+y,(x).end()
#define decp(x) fixed << setprecision(x)
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
	int t,x,y;
	bool operator < (const A&o) const{
		if(t!=o.t)	return t<o.t;
		if(x!=o.x)	return x<o.x;
					return y<o.y;
	}
};
vector<A > ans;
void div(int sti,int eni,int stj,int enj,int i,int j){
	if(sti == eni and stj == enj)	return;
	// printf("%d %d %d %d %d %d\n",sti,stj,eni,enj,i,j);
	int mi = (sti + eni)/2,mj = (stj + enj)/2;
	//upleft = (sti -> mi,stj -> mj)
	//upright = (sti -> mi,mj+1 -> enj)
	//downleft = (mi+1 -> eni,stj -> mj)
	//downright = (mi+1 -> eni,mj+1 -> enj)
	if(i<=mi and j<=mj){
		ans.push_back({0,mj,mi});
		div(sti,mi,stj,mj,i,j);						//1
		div(sti,mi,mj + 1,enj,mi,mj + 1);			//2
		div(mi + 1,eni,stj,mj,mi + 1,mj);			//3
		div(mi + 1,eni,mj + 1,enj,mi + 1,mj + 1);	//4
	}else if(i<=mi and j<=enj){
		ans.push_back({1,mj,mi});
		div(sti,mi,mj + 1,enj,i,j);					//2
		div(sti,mi,stj,mj,mi,mj);					//1
		div(mi + 1,eni,stj,mj,mi + 1,mj);			//3
		div(mi + 1,eni,mj + 1,enj,mi + 1,mj + 1);	//4
	}else if(i<=eni and j<=mj){
		ans.push_back({2,mj,mi});
		div(mi + 1,eni,stj,mj,i,j);					//3
		div(sti,mi,stj,mj,mi,mj);					//1
		div(sti,mi,mj + 1,enj,mi,mj + 1);			//2
		div(mi + 1,eni,mj + 1,enj,mi + 1,mj + 1);	//4
	}else if(i<=eni and j<=enj){
		ans.push_back({3,mj,mi});
		div(mi + 1,eni,mj + 1,enj,i,j);				//4
		div(sti,mi,stj,mj,mi,mj);					//1
		div(sti,mi,mj + 1,enj,mi,mj + 1);			//2
		div(mi + 1,eni,stj,mj,mi + 1,mj);			//3
	}
}
void solve(){
	int n,x,y;
	cin >> n >> x >> y;
	div(0,n-1,0,n-1,y,x);
	sort(all(ans));
	cout << ans.size() << '\n';
	for(auto x:ans)
		cout << x.t << ' ' << x.x << ' ' << x.y << '\n';
}
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int q = 1;
	// cin >> q;
	while(q--){
		solve();
	}
	return 0;
}