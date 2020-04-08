/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int dp[4000010];
string str;
int k;
int dfs(int sum){
	if(dp[sum]!=-1)	return dp[sum];
	int temp = sum,sum2 = 0;
	while(temp>0){
		sum2+=pow(temp%10,k);
		temp/=10;
	}
	dp[sum] = 0;
	if(sum == sum2)	return dp[sum] = 1;
	else			return dp[sum] = dfs(sum2);
}
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	memset(dp,-1,sizeof dp);
	int n,sum,temp,sum2;
	cin >> n >> k;
	while(n--){
		cin >> str;
		sum = sum2 = 0;
		for(auto x:str)
			sum+=pow(x-'0',k);
		temp = sum;
		while(temp>0){
			sum2+=pow(temp%10,k);
			temp/=10;
		}
		if(sum == sum2)	dp[sum] = 1;
		printf((dfs(sum2))?"Yes\n":"No\n");
	}
	return 0;
}
