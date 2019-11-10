/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int dp[1005][8][3][1005],stay[3];
int main(){
    int n,a = 0,b = 1,c = 2;
    cin >> n >> stay[a] >> stay[b] >> stay[c];
    dp[1][1<<a][a][1] = 1;
    for(int i=2;i<=n;i++){
        for(int j=0;j<8;j++){
            //a->b && a->c
            for(int k=1;k<=stay[a];k++){
                dp[i][j|(1<<b)][b][1]+=dp[i-1][j][a][k];
                dp[i][j|(1<<b)][b][1]%=MOD;
                dp[i][j|(1<<c)][c][1]+=dp[i-1][j][a][k];
                dp[i][j|(1<<c)][c][1]%=MOD;
            }
            printf("%d : %d\n",i,dp[i][j|(1<<c)][c][1]);
            //b->c
            for(int k=1;k<=stay[b];k++){
                dp[i][j|(1<<c)][c][1]+=dp[i-1][j][b][k];
                dp[i][j|(1<<c)][c][1]%=MOD;
            }
            //c->a
            for(int k=1;k<=stay[c];k++){
                dp[i][j|(1<<a)][a][1]+=dp[i-1][j][c][k];
                dp[i][j|(1<<a)][a][1]%=MOD;
            }
            //Stay at same place
            for(int l=2;l<=stay[a];l++)
                dp[i][j][a][l] = dp[i-1][j][a][l-1];
            for(int l=2;l<=stay[b];l++)
                dp[i][j][b][l] = dp[i-1][j][b][l-1];
            for(int l=2;l<=stay[c];l++)
                dp[i][j][c][l] = dp[i-1][j][c][l-1];
        }
    }
    int ans = 0;
    for(int k=1;k<=stay[a];k++){
        ans+=dp[n][7][a][k];
        ans%=MOD;
    }
    for(int k=1;k<=stay[b];k++){
        ans+=dp[n][7][b][k];
        ans%=MOD;
    }
    for(int k=1;k<=stay[c];k++){
        ans+=dp[n][7][c][k];
        ans%=MOD;
    }
    printf("%d\n",ans);
    return 0;
}
