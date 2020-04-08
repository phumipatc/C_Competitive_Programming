/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int dp[310][310],banner[310][310];
int place(int l,int r){
	if(dp[l][r]!=-1)	return dp[l][r];
	if(l == r)			return dp[l][r] = banner[l][r];
	int maxx = 0;
	for(int i=l;i<r;i++)
		maxx = max(maxx,place(l,i)+place(i+1,r));
	return dp[l][r] = maxx+banner[l][r];
}
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int n,m,u,v,all;
	cin >> n >> m;
	all = m;
	while(m--){
		cin >> u >> v;
		banner[u][v]++;
	}
	memset(dp,-1,sizeof dp);
	cout << all-place(1,n) << '\n';
	return 0;
}