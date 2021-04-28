/*
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Algo	: QS
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
	if(b == 0)	return 1;
	if(b == 1)	return a%c;
	LL now = modN(a,b/2);
	if(b&1)	return (((now*now)%c)*(a%c))%c;
	else	return (now*now)%c;
}
int a[50010];
int dp[100010][2];
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int n,q,maxx,minn,u,v;
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	for(int i=2;i<=n;i++){
		maxx = max(a[i],a[i-1])-1;
		minn = min(a[i],a[i-1])+1;
		if(maxx<minn)	continue;
		// printf("%d %d\n",minn,maxx);
		if(minn%2)	dp[minn][1]++,dp[minn+1][0]++;
		else		dp[minn+1][1]++,dp[minn][0]++;
		if(maxx%2)	dp[maxx+2][1]--,dp[maxx+1][0]--;
		else		dp[maxx+1][1]--,dp[maxx+2][0]--;
	}
	for(int i=2;i<=100000;i++){
		dp[i][0]+=dp[i-2][0];
		dp[i][1]+=dp[i-2][1];
		// printf("%d %d\n",dp[i][0],dp[i][1]);
	}
	for(int i=1;i<=100000;i++){
		dp[i][0]+=dp[i-1][0];
		dp[i][1]+=dp[i-1][1];
	}
	cin >> q;
	while(q--){
		cin >> u >> v;
		cout << dp[v][0]-dp[max(0,u-1)][0] << ' ' << dp[v][1]-dp[max(0,u-1)][1] << '\n';
	}
	return 0;
}