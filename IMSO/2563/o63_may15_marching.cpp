/*
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Algo	:
	Status	:
*/
#include<bits/stdc++.h>
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
	if(b == 0)	return 0;
	if(b == 1)	return a%c;
	LL now = modN(a,b/2);
	if(b&1)	return (((now*now)%c)*(a%c))%c;
	else	return (now*now)%c;
}
int a[1510][1510];
LL dp11[1510][1510],dp1c[1510][1510],dpr1[1510][1510],dprc[1510][1510],qs[1510][1510];
priority_queue<LL > heap;
void solve(){
	int r,c;
	cin >> r >> c;
	for(int i=0;i<=r+1;i++){
		for(int j=0;j<=c+1;j++){
			dp11[i][j] = dp1c[i][j] = dpr1[i][j] = dprc[i][j] = 1e9;
		}
	}
	dp11[0][1] = dp11[1][0] = 0;
	dprc[r][c+1] = dprc[c][r+1] = 0;
	dp1c[0][c] = dp1c[1][c+1] = 0;
	dpr1[r+1][1] = dpr1[0][r] = 0;
	for(int i=1;i<=r;i++)
		for(int j=1;j<=c;j++)
			cin >> a[i][j],qs[i][j] = a[i][j] + qs[i][j-1];
	for(int i=1;i<=r;i++){
		for(int j=1;j<=c;j++)
			dp11[i][j] = a[i][j] + min(dp11[i-1][j],dp11[i][j-1]);
		for(int j=c;j>=1;j--)
			dp1c[i][j] = a[i][j] + min(dp1c[i-1][j],dp1c[i][j+1]);
	}
	for(int i=r;i>=1;i--){
		for(int j=c;j>=1;j--)
			dprc[i][j] = a[i][j] + min(dprc[i+1][j],dprc[i][j+1]);
		for(int j=1;j<=c;j++)
			dpr1[i][j] = a[i][j] + min(dpr1[i+1][j],dpr1[i][j-1]);
	}
	// for(int i=1;i<=r;i++){
	// 	for(int j=1;j<=c;j++)
	// 		printf("%lld ",dpr1[i][j]);
	// 	printf("\n");
	// }
	LL ans = 1e18;
	for(int i=1;i<=r;i++){
		while(!heap.empty())	heap.pop();
		for(int j=1;j<=c;j++){
			heap.push(-(dp11[i][j] + dpr1[i][j] - (2*a[i][j]) - qs[i][j-1]));
			ans = min(ans,dprc[i][j] + dp1c[i][j] - (2*a[i][j]) + qs[i][j] - heap.top());
		}
	}
	for(int j=1;j<=c;j++)
		for(int i=1;i<=r;i++)
			qs[i][j] = a[i][j] + qs[i-1][j];
	for(int j=1;j<=c;j++){
		while(!heap.empty())	heap.pop();
		for(int i=1;i<=r;i++){
			heap.push(-(dp11[i][j] + dp1c[i][j] - (2*a[i][j]) - qs[i-1][j]));
			ans = min(ans,dprc[i][j] + dpr1[i][j] - (2*a[i][j]) + qs[i][j] - heap.top());
		}
	}
	cout << ans << '\n';
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int q = 1;
	// cin >> q;
	for(int Q=1;Q<=q;Q++){
		// cout << "Case #" << Q << ": ";
		solve();
	}
	return 0;
}
/*
5 10
2 6 1 7 4 8 5 6 9 6
8 8 7 6 8 3 6 1 3 3
1 4 3 1 7 5 8 5 1 4
9 5 6 8 5 7 8 5 4 9
8 6 7 8 9 9 2 6 5 1
*/