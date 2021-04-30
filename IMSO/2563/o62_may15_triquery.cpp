/*
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Algo	: FW + Observe
	Status	: Finished
*/
#include<bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x),end(x)
#define allst(x,y) (x).begin()+y,(x).end()
#define sz(x) (int)(x).size()
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
LL modN(LL a,LL b,LL c = MOD){
	if(b == 0)	return 1;
	if(b == 1)	return a%c;
	LL now = modN(a,b/2,c);
	if(b&1)	return (((now*now)%c)*(a%c))%c;
	else	return (now*now)%c;
}
int N,M;
LL tri[4010][2010],rect[2010][2010];
void updtri(int x,int y,int v){
	for(int i=x;i<=2*N;i+=(i&-i))
		for(int j=y;j<=N;j+=(j&-j))
			tri[i][j]+=v;
}
void updrect(int x,int y,int v){
	for(int i=x;i<=N;i+=(i&-i))
		for(int j=y;j<=N;j+=(j&-j))
			rect[i][j]+=v;
}
LL qrytri(int x,int y,LL sum=0){
	for(int i=x;i;i-=(i&-i))
		for(int j=y;j;j-=(j&-j))
			sum+=tri[i][j];
	return sum;
}
LL qryrect(int x,int y,LL sum=0){
	for(int i=x;i;i-=(i&-i))
		for(int j=y;j;j-=(j&-j))
			sum+=rect[i][j];
	return sum;
}
void upd(int x1,int y1,int x2,int y2,int v){
	updtri(x1,y1,v);	updtri(x1,y2+1,-v);
	updtri(x2+1,y1,-v);	updtri(x2+1,y2+1,v);
}
void solve(){
	int T,R,C;
	cin >> T >> R >> C;
	if(T == 1){
		int L;
		cin >> L;
		cout << qrytri((R-L)+C+1,C)
				- qrytri((R-L)+C+1,C-L)
				- (qryrect(N,C) - qryrect(R,C) - qryrect(N,C-L) + qryrect(R,C-L)) << '\n';
	}else{
		int V;
		cin >> V;
		V-=qryrect(R,C) - qryrect(R-1,C) - qryrect(R,C-1) + qryrect(R-1,C-1);
		upd(C+1,C,R+C,N,V/2);
		upd(C+1,C,R+C-1,N,V/2);
		updrect(R,C,V);
	}
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cin >> N >> M;
	for(int Q=1;Q<=M;Q++){
		// cout << "Case #" << Q << ": ";
		solve();
	}
	return 0;
}