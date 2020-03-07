/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL a[110][110],dp[110][110],from[110][110];
stack<int > ans;
int main(){
	// freopen("7.in","r",stdin);
	// freopen("7.sol","w",stdout);
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int n,m;
	cin >> n >> m;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin >> a[i][j];
	for(int i=0;i<n;i++)
		dp[i][0] = a[i][0];
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			from[i][j] = 1e9;
	for(int j=1;j<m;j++){
		for(int i=0;i<n;i++){
			LL up = dp[(i+n-1)%n][j-1];
			LL l = dp[i][j-1];
			LL down = dp[(i+1)%n][j-1];
			if(up<=l && up<=down){
				from[i][j] = min(from[i][j],(LL )(i+n-1)%n);
				dp[i][j] = up+a[i][j];
			}
			if(l<=up && l<=down){
				from[i][j] = min(from[i][j],(LL )i);
				dp[i][j] = l+a[i][j];
			}
			if(down<=l && down<=up){
				from[i][j] = min(from[i][j],(LL )(i+1)%n);
				dp[i][j] = down+a[i][j];
			}
		}
	}
	LL minn = 1e18;
	pair<int ,int > pos;
	pos.second = m-1;
	for(int i=0;i<n;i++){
		if(minn>dp[i][m-1]){
			minn = dp[i][m-1];
			pos.first = i;
		}
	}
	cout << minn << '\n';
	while(pos.second>=0){
		ans.push(pos.first+1);
		pos.first = from[pos.first][pos.second];
		pos.second--;
	}
	while(!ans.empty()){
		cout << ans.top() << ' ';
		ans.pop();
	}
	return 0;
}
/*
4 8
7 1 8
10 4 1 -5 -1
4 16 5 3 9 5 -3 -9
2 24 4 6 7 4 0 -2
6 10 3 7 2 11 -7 -4

//If bug
//Debug: Need to be Backward
*/