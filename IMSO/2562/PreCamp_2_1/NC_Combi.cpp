/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long LL;
int dp[110][110][110][110];
int a,b,ka,kb;
int place(int n,int m,int nn,int mm){
	if(dp[n][m][nn][mm]!=-1)	return dp[n][m][nn][mm];
	if(n == a && m == b)		return dp[n][m][nn][mm] = 1;
	int sum = 0;
	if(n<a && nn<ka)	sum+=place(n+1,m,nn+1,0),sum%=MOD;
	if(m<b && mm<kb)	sum+=place(n,m+1,0,mm+1),sum%=MOD;
	return dp[n][m][nn][mm] = sum;
}
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	cin >> a >> b >> ka >> kb;
	memset(dp,-1,sizeof dp);
	cout << place(0,0,0,0) << '\n';
	return 0;
}