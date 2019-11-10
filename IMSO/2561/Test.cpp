/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
long long dp[105][105],qs[105][105];
int main(){
    freopen("0_in.txt","r",stdin);
    freopen("0_out.txt","w",stdout);
    long long n,k;
    cin >> n >> k;
    dp[0][0] = qs[0][0] = 1;
    for(long long i=1;i<=n;i++)
        qs[i][0] = qs[0][i] = 1;
    for(long long i=1;i<=n;i++){
        for(long long j=1;j<=n;j++){
            for(long long l=1;l<=k;l++){
                if(i-l-1>=0)    dp[i][j]+=qs[i-l-1][j-1],dp[i][j]%=MOD;
                if(j-l-1>=0)    dp[i][j]+=qs[i-1][j-l-1],dp[i][j]%=MOD;
            }
            qs[i][j] = (dp[i][j]+qs[i-1][j]+qs[i][j-1]-qs[i-1][j-1]+MOD)%MOD;
            printf("%lld %lld : %lld\n",i,j,dp[i][j]);
        }
    }
    cout << qs[n][n]-1 << endl;
    return 0;
}
