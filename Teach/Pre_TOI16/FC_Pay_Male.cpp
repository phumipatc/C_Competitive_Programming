/*
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Algo	: DP
	Status	: Finished
*/
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int ,int >;
using PLL = pair<long long ,long long >;
const int dir4[2][4] = {{1,-1,0,0},{0,0,1,-1}};
const int dir8[2][8] = {{-1,-1,-1,0,1,1,1,0},{-1,0,1,1,-1,0,1,-1}};
const int MOD = 100003;
int dp[110][110][110][3];
int pay(int a,int b,int c,int last){
	if(a<0 || b<0 || c<0)		return 0;
	if(dp[a][b][c][last]!=-1)	return dp[a][b][c][last];
	int sum = 0;
	if(last == 0){
		sum+=pay(a,b-1,c,1),sum%=MOD;
		sum+=pay(a,b,c-1,2),sum%=MOD;
	}else if(last == 1){
		sum+=pay(a-1,b,c,0),sum%=MOD;
		sum+=pay(a,b,c-1,2),sum%=MOD;
	}else{
		sum+=pay(a,b-1,c,1),sum%=MOD;
		sum+=pay(a-1,b,c,0),sum%=MOD;
	}
	return dp[a][b][c][last] = sum;
}
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int q,a,b,c,sum;
	cin >> q;
	memset(dp,-1,sizeof dp);
	for(int i=0;i<3;i++)	dp[0][0][0][i] = 1;
	dp[1][0][0][0] = dp[0][1][0][1] = dp[0][0][1][2] = 0;
	while(q--){
		cin >> a >> b >> c;
		sum = pay(a-1,b,c,0),sum%=MOD;
		sum+= pay(a,b-1,c,1),sum%=MOD;
		sum+= pay(a,b,c-1,2),sum%=MOD;
		cout << sum << '\n';
	}
	return 0;
}