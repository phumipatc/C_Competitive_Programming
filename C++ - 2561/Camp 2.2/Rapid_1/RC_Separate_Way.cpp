/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
vector<pair<int ,int >> lv[510];
int dp[510][255][255];
bool checkk(pair<int ,int > a,pair<int ,int > b){
	if(a.first == b.first){
		if(a.second == b.second+1)	return 1;
		else						return 0;
	}else if(a.first == b.first+1){
		if(a.second == b.second)	return 1;
		else						return 0;
	}
	return 0;
}
int main(){
	int n,m,countt = 0,nj,nk;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++,countt++)
		for(int j=1;j<=m;j++)
			lv[j+countt].push_back({i,j});
	dp[1][0][0] = 1;
	for(int i=2;i<n+m;i++){
		for(int j=0;j<lv[i].size();j++){
			for(int k=0;k<lv[i].size();k++){
				for(int x=-1;x<=1;x++){
					for(int y=-1;y<=1;y++){
						nj = j+x,nk = k+y;
						if(nj<0 || nk<0 || nj>=lv[i-1].size() || nk>=lv[i-1].size())		continue;
						if(j == k && nj == nk)												continue;
						if(!checkk(lv[i][j],lv[i-1][nj]) || !checkk(lv[i][k],lv[i-1][nk]))	continue;
						dp[i][j][k] = (((dp[i][j][k]+dp[i-1][nj][nk])%MOD)+MOD)%MOD;
					}
				}
			}
		}
	}
	printf("%d\n",dp[n+m-1][0][0]);
	return 0;
}
