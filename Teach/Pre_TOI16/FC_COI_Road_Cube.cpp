/*
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Algo	: Sliding Window
	Status	: Finished
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int ,int > PII;
typedef pair<long long ,long long > PLL;
int dir4[2][4] = {{1,-1,0,0},{0,0,1,-1}};
int dir8[2][8] = {{-1,-1,-1,0,1,1,1,0},{-1,0,1,1,-1,0,1,-1}};
int a[110][10010],dp[110][10010];
deque<PII > deq;
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int n,m,k,maxx = -1e9;
	cin >> n >> m >> k;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin >> a[i][j];
	for(int j=1;j<=m;j++)
		dp[1][j] = a[1][j];
	for(int i=2;i<=n;i++){
        deq.clear();
		for(int j=1;j<=k;j++){
			while(!deq.empty() && deq.back().second<dp[i-1][j])	deq.pop_back();
			deq.push_back({j,dp[i-1][j]});
		}
		for(int j=1;j<=m;j++){
			while(!deq.empty() && deq.front().first<j-k)			deq.pop_front();
			if(j+k<=m){
				while(!deq.empty() && deq.back().second<dp[i-1][j+k])	deq.pop_back();
				deq.push_back({j+k,dp[i-1][j+k]});
			}
			dp[i][j] = a[i][j]+deq.front().second;
			maxx = max(maxx,dp[i][j]);
		}
	}
	cout << maxx << '\n';
	return 0;
}
