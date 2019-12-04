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
void debug(int n,int m){
    printf("\n");
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            printf("%d ",dp[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
int main(){
    ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
    int n,m,K,t,u,l;
    cin >> n >> m >> K >> t;
    for(int k=0;k<K;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin >> gate[i][j][k].first >> gate[i][j][k].second;
                if(k == 0)  continue;
                gate[i][j][k].first = max(gate[i][j][k].first,gate[i][j][k-1].first);
                gate[i][j][k].second = max(gate[i][j][k].second,gate[i][j][k-1].second);
            }
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin >> num[i][j];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i == 0 || j == 0)    dp[i][j] = 1e9;
            else                    dp[i][j] = -1e9;
        }
    }
    dp[1][1] = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(i == 1 && j == 1)    continue;
            for(int k=0;k<=num[i][j];k++){
                dp[i][j] =  max(dp[i][j],min(
                            dp[i-1][j]+gate[i][j][min(K-1,k)].first,
                            dp[i][j-1]+gate[i][j][min(K-1,num[i][j]-k)].second));
            }
        }
    }
    // debug(n,m);
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