/*
	Task	: PZ_Scholarships
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 15 May 2021 [14:44]
	Algo	: Observe & DP
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
	if(b == 0)	return 0;
	if(b == 1)	return a%c;
	LL now = modN(a,b/2);
	if(b&1)	return (((now*now)%c)*(a%c))%c;
	else	return (now*now)%c;
}
int a[1010][1010],b[1010][1010];
LL dp11[2][1010],dprc[1010][1010];
void solve(){
	int r,c,K;
	scanf("%d %d %d",&r,&c,&K);
	for(int i=1;i<=r;i++)
		for(int j=1;j<=c;j++)
			scanf("%d",&a[i][j]),b[i][j] = a[i][j];
	if(K == 2){
		for(int i=1;i<=r;i++)
			for(int j=1;j<=c;j++)
				scanf("%d",&b[i][j]);
	}
	//Preprocess dprc
	for(int i=r;i>=1;i--){
		for(int j=c;j>=1;j--){
			dprc[i][j] = 1e18;
			if(i == r && j == c)	dprc[i][j] = b[i][j];
			if(i+1<=r)	dprc[i][j] = min(dprc[i][j],dprc[i+1][j]+b[i][j]);
			if(j+1<=c)	dprc[i][j] = min(dprc[i][j],dprc[i][j+1]+b[i][j]);
		}
	}

	LL minn = 1e18;
	//Preprocess dp11
	for(int i=1;i<=r;i++){
		for(int j=1;j<=c;j++){
			dp11[i&1][j] = 1e18;
			if(i == 1 && j == 1)	dp11[i&1][j] = a[i][j];
			if(i-1>0)	dp11[i&1][j] = min(dp11[i&1][j],dp11[(i&1)^1][j]+a[i][j]);
			if(j-1>0)	dp11[i&1][j] = min(dp11[i&1][j],dp11[i&1][j-1]+a[i][j]);
			minn = min(minn,dp11[i&1][j]+dprc[i][j]-max(a[i][j],b[i][j]));
		}
	}
	printf("%lld\n",minn);
}
int main(){
	int q = 1;
	scanf("%d",&q);
	for(int Q=1;Q<=q;Q++){
		// cout << "Case #" << Q << ": ";
		solve();
	}
	return 0;
}
