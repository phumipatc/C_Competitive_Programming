/*
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Algo	: 
	Status	: 
*/
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int ,int >;
using PLL = pair<long long ,long long >;
const int dir4[2][4] = {{1,-1,0,0},{0,0,1,-1}};
const int dir8[2][8] = {{-1,-1,-1,0,1,1,1,0},{-1,0,1,1,-1,0,1,-1}};
int qs[100010],dp[100010][110];
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int n,k,p;
	cin >> n >> k >> p;
	for(int i=1;i<=n;i++){
		cin >> qs[i];
		qs[i]+=qs[i-1];
	}
	if(n<=k*p){
		printf("%d\n",qs[n]);
		return 0;
	}
	for(int i=p;i<=n;i++){
		for(int j=1;j<=k;j++){
			dp[i][j] = qs[i]-qs[i-p]+dp[i-p][j-1];
			dp[i][j] = max(dp[i][j],dp[i-1][j]);
		}
	}
	cout << dp[n][k] << '\n';
	return 0;
}