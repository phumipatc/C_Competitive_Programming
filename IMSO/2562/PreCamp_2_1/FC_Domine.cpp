/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int dp[1010][1010][10],a[1010][5];
int main()
{
    int n,k,maxx=-1e9;
	cin >> n >> k;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=3;j++)
			cin >> a[i][j];
    for(int i=0;i<=n;i++)
        for(int j=1;j<=k;j++)
            for(int K=0;K<8;K++)
                dp[i][j][K] = -1e9;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            dp[i][j][0] = dp[i-1][j][7];
            if(i>1){
                dp[i][j][1] = max(dp[i][j][0],dp[i-1][j-1][6] + a[i][3] + a[i-1][3]);
                dp[i][j][2] = max(dp[i][j][0],dp[i-1][j-1][5] + a[i][2] + a[i-1][2]);
                dp[i][j][4] = max(dp[i][j][0],dp[i-1][j-1][3] + a[i][1] + a[i-1][1]);
            }
            dp[i][j][1] = max(dp[i][j][0],dp[i][j][1]);
            dp[i][j][2] = max(dp[i][j][0],dp[i][j][2]);
            dp[i][j][3] = max(dp[i][j][0],max(dp[i-1][j-1][7] + a[i][2] + a[i][3],max(dp[i][j][1],dp[i][j][2])));
            dp[i][j][4] = max(dp[i][j][0],dp[i][j][4]);
            if(i>1 && j >= 2)
				dp[i][j][5] = max(dp[i][j][0],max(dp[i-1][j-2][2] + a[i][1] + a[i][3] + a[i-1][1] + a[i-1][3],max(dp[i][j][1],dp[i][j][4])));
            dp[i][j][5] = max(dp[i][j][0],dp[i][j][5]);
			dp[i][j][6] = max(dp[i][j][0],max(dp[i-1][j-1][7] + a[i][1] + a[i][2],max(dp[i][j][4],dp[i][j][2])));
        	if(i>1 && j>=2)
                dp[i][j][7] = max(dp[i-1][j-2][3] + a[i-1][1] + a[i][1] + a[i][2] + a[i][3],dp[i-1][j-2][6] + a[i-1][3] + a[i][1] + a[i][2] + a[i][3]);
            if(i>1&& j>=3)
                dp[i][j][7] = max(dp[i][j][7],dp[i-1][j-3][0] + a[i-1][1] + a[i-1][2] + a[i-1][3] + a[i][1] + a[i][2] + a[i][3]);
            for(int K=0;K<7;K++)
                dp[i][j][7] = max(dp[i][j][7],dp[i][j][K]);
        }
    }
    for(int K=0;K<8;K++)
        maxx = max(maxx,dp[n][k][K]);
    cout << maxx << '\n';
}
/*
3
1 2 3
2 3 4
3 4 8
*/
