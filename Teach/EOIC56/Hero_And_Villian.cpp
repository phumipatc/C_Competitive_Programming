/*
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
pair<int ,int > gate[210][210][110];
int dp[210][210],num[210][210];
int main(){
    ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
    int n,m,K,t;
    cin >> n >> m >> K >> t;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            for(int k=0;k<K;k++)
                cin >> gate[i][j][k].first >> gate[i][j][k].second;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> num[i][j];
            num[i][j] = min(num[i][j],K);
            dp[i][j] = 1e9;
        }
    }
    dp[1][1] = 0;
    for(int i=2;i<=n;i++){
        int temp = gate[i][1][0].first;
        for(int k=0;k<=num[i][1];k++)
            temp = max(temp,gate[i][1][k%K].first);
        dp[i][1] = min(dp[i][1],dp[i-1][1]+temp);
    }
    for(int j=2;j<=m;j++){
        int temp = gate[1][j][0].second;
        for(int k=0;k<=num[1][j];k++)
            temp = max(temp,gate[1][j][k%K].second);
        dp[1][j] = min(dp[1][j],dp[1][j-1]+temp);
    }
    for(int i=2;i<=n;i++){
        for(int j=2;j<=m;j++){
            int temp = gate[i][j][0].first;
            for(int k=0;k<=num[i][j];k++)
                temp = max(temp,gate[i][j][k%K].first);
            dp[i][j] = min(dp[i][j],dp[i-1][j]+temp);
            temp = gate[1][j][0].second;
            for(int k=0;k<=num[i][j];k++)
                temp = max(temp,gate[i][j][k%K].second);
            dp[i][j] = min(dp[i][j],dp[i][j-1]+temp);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            printf("%d ",dp[i][j]);
        }
        printf("\n");
    }
    if(dp[n][m]<=t)
        cout << "Peatland is protected\n" << dp[n][m] << '\n';
    else
        cout << "Peatland is destroyed\n" << dp[n][m]-t << '\n';
    return 0;
}
/*
3 3 3 18
2 8 5 1 10 5
9 9 3 5 6 6
2 8 2 2 6 3
8 7 2 5 3 4
3 3 2 7 9 6
8 7 2 9 10 3
8 10 6 5 4 2
3 4 4 5 2 2
4 9 8 5 3 8
2 4 3
1 4 3
1 0 0
*/