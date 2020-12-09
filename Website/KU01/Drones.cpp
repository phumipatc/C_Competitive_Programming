/*
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Algo	: DP
	Status	: Unfinished (30 pt.)
*/
#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define allst(x,y) (x).begin()+y,(x).end()
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
vector<int > a;
int qs[1010],dp[1010][210];
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int n,m = 200;
	cin >> n;
	a.resize(n+1);
	for(int i=1;i<=n;i++)
		cin >> a[i];
	sort(allst(a,1));	reverse(allst(a,1));
	for(int i=1;i<=n;i++)
		qs[i] = a[i]+qs[i-1];
	for(int i=0;i<=n;i++)
		for(int j=0;j<=200;j++)
			dp[i][j] = 1e9;
	dp[0][0] = 0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			for(int k=i-1;k>=i-10 && k>=0;k--){
				dp[i][j] = min(dp[i][j],dp[k][j-1] + (qs[i]-qs[k])*j*2 - (qs[k+1]-qs[k])*j);
			}
			// printf("%d %d %d\n",i,j,dp[i][j]);
		}
	}
	int minn = 1e9;
	for(int i=1;i<=m;i++)
		minn = min(minn,dp[n][i]);
	cout << minn << '\n';
	return 0;
}