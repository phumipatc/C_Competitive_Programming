/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
pair<int ,int > a[42],b[42];
int dp[42][42][42];
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	// freopen("1.sol","w",stdout);
	int q,d,m,r,ka,kb;
	cin >> q;
	while(q--){
		cin >> d >> m >> r >> ka >> kb;
		for(int i=1;i<=m;i++)
			cin >> a[i].first;
		for(int i=1;i<=m;i++)
			cin >> b[i].first;
		for(int i=1;i<=m;i++)
			cin >> a[i].second;
		for(int i=1;i<=m;i++)
			cin >> b[i].second;
		for(int i=0;i<=m;i++)
			for(int j=0;j<=ka;j++)
				for(int k=0;k<=kb;k++)
					dp[i][j][k] = 1e9;
		dp[0][0][0] = 0;
		for(int i=1;i<=m;i++){
			if(a[i].second!=-1){
				for(int j=a[i].second;j<=ka;j++){
					for(int k=0;k<=kb;k++){
						if(j+k>r)	break;
						dp[i][j][k] = min(dp[i][j][k],dp[i-1][j-a[i].second][k]+a[i].first);
						// if(dp[i][j][k] == 1e9)	continue;
						// printf("%d %d %d: %d\n",i,j,k,dp[i][j][k]);
					}
				}
			}
			if(b[i].second!=-1){
				for(int k=b[i].second;k<=kb;k++){
					for(int j=0;j<=ka;j++){
						if(j+k>r)	break;
						dp[i][j][k] = min(dp[i][j][k],dp[i-1][j][k-b[i].second]+b[i].first);
						// if(dp[i][j][k] == 1e9)	continue;
						// printf("%d %d %d: %d\n",i,j,k,dp[i][j][k]);
					}
				}
			}
		}
		int maxx = 0;
		for(int j=0;j<=ka;j++){
			for(int k=0;k<=kb;k++){
				if(j+k>r)			break;
				if(dp[m][j][k]>d)	continue;
				maxx = max(maxx,r-(j+k));
			}
		}
		if(maxx == 0)	cout << "-1\n";
		else			cout << maxx << '\n';
	}
	return 0;
}
/*
2
200 4 10
5 4
5 8 -1 10
100 200 100 50
1 2 -1 3
1 3 2 2
200 4 50
10 10
5 8 -1 10
100 200 200 50
1 2 -1 3
1 3 2 2
*/