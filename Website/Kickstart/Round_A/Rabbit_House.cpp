/*
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Algo	: Heap + Implementing
	Status	: Finished
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
	int i,j,v;
	bool operator < (const A&o) const{
		return v<o.v;
	}
};
priority_queue<A > heap;
int a[310][310],b[310][310],mark[310][310];
void solve(){
	int r,c;
	LL ans = 0;
	cin >> r >> c;
	for(int i=1;i<=r;i++)
		for(int j=1;j<=c;j++)
			cin >> a[i][j],b[i][j] = a[i][j],heap.push({i,j,a[i][j]});
	memset(mark,0,sizeof mark);
	while(!heap.empty()){
		A now = heap.top();
		heap.pop();
		if(mark[now.i][now.j])	continue;
		mark[now.i][now.j] = 1;
		for(int k=0;k<4;k++){
			int ni = now.i+dir4[0][k],nj = now.j+dir4[1][k];
			if(ni<=0 || nj<=0 || ni>r || nj>c)	continue;
			a[ni][nj]+=max(0,now.v-a[ni][nj]-1);
			heap.push({ni,nj,a[ni][nj]});
		}
	}
	for(int i=1;i<=r;i++)
		for(int j=1;j<=c;j++)
			ans+=a[i][j]-b[i][j];
	cout << ans << '\n';
}
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int q = 1;
	cin >> q;
	for(int Q=1;Q<=q;Q++){
		cout << "Case #" << Q << ": ";
		solve();
	}
	return 0;
}