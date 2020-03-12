/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
struct A{
	int i,j,w;
	bool operator < (const A&o) const{
		if(i!=o.i)		return i<o.i;
		else if(j!=o.j)	return j<o.j;
		else			return w<o.w;
	}
};
A ans[10010];
int dp[110][110];
char a[110][110];
int main(){
	int r,c,countt = 0;
	scanf("%d %d",&r,&c);
	for(int i=1;i<=r;i++){
		for(int j=1;j<=c;j++){
			scanf(" %c",&a[i][j]);
			if(a[i][j] == '.')	continue;
			dp[i][j] = min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]))+1;
		}
	}
	for(int i=1;i<=r;i++){
		for(int j=1;j<=c;j++){
			if(dp[i][j]+1 == dp[i+1][j])	continue;
			if(dp[i][j]+1 == dp[i][j+1])	continue;
			if(dp[i][j]+1 == dp[i+1][j+1])	continue;
			if(a[i][j] == '.')				continue;
			// cout << i << ' ' << j << '\n';
			ans[countt++] = {i-dp[i][j]+1,j-dp[i][j]+1,dp[i][j]};
		}
	}
	sort(ans,ans+countt);
	for(int i=0;i<countt;i++)
		cout << ans[i].i << ' ' << ans[i].j << ' ' << ans[i].w << '\n';
	return 0;
}
/*
5 5
###..
#####
#####
.###.
.#.#.
*/