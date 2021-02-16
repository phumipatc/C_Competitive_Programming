/*
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Algo	:
	Status	:
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
int a[32][32],qs[32][32][910];
int dp[32][32][32][32],mark[910];
int n,m,all,in_range;
int cut(int sti,int stj,int eni,int enj){
	int cnt = 0;
	memset(mark,0,sizeof mark);
	for(int i=sti;i<=eni;i++){
		for(int j=stj;j<=enj;j++){
			if(mark[a[i][j]])	continue;
			all = qs[n][m][a[i][j]];
			in_range = qs[eni][enj][a[i][j]]
						- qs[eni][stj-1][a[i][j]] - qs[sti-1][enj][a[i][j]]
						+ qs[sti-1][stj-1][a[i][j]];
			cnt+=(all == in_range);
			mark[a[i][j]] = 1;
		}
	}
	return cnt;
}
int div(int sti,int stj,int eni,int enj){
	if(dp[sti][stj][eni][enj]!=-1)	return dp[sti][stj][eni][enj];
	if(sti == eni or stj == enj)	return dp[sti][stj][eni][enj] = cut(sti,stj,eni,enj);

	int maxx = 0;
	//cut left
	maxx = max(maxx,cut(sti,stj,eni,stj) + div(sti,stj+1,eni,enj));

	//cut right
	maxx = max(maxx,cut(sti,enj,eni,enj) + div(sti,stj,eni,enj-1));

	//cut up
	maxx = max(maxx,cut(sti,stj,sti,enj) + div(sti+1,stj,eni,enj));

	//cut down
	maxx = max(maxx,cut(eni,stj,eni,enj) + div(sti,stj,eni-1,enj));

	// printf("%d %d %d %d: %d\n",sti,stj,eni,enj,maxx);
	return dp[sti][stj][eni][enj] = maxx;
}
void solve(){
	int k;
	cin >> n >> m >> k;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin >> a[i][j];
			qs[i][j][a[i][j]]++;
			for(int l=1;l<=k;l++)
				qs[i][j][l]+=qs[i-1][j][l] + qs[i][j-1][l] - qs[i-1][j-1][l];
		}
	}
	memset(dp,-1,sizeof dp);
	cout << div(1,1,n,m) << '\n';
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