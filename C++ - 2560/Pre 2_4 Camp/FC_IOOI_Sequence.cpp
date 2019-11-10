/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long dp[5050][5050],qs[5050][5050];
int main()
{
    long long n,k,i,j,ans=0;
    scanf("%lld %lld",&n,&k);
    dp[0][0] = dp[1][1] = qs[0][0] = qs[1][0] = qs[1][1] = 1;
    for(i=2;i<=n;i++){
        qs[i][0]+=qs[i-1][0];
        for(j=1;j<=n;j++){
            dp[i][j]+=qs[i-1][j-1];
            if(i-k-1>=0)
                dp[i][j]=(((dp[i][j]-qs[i-k-1][j-1])%2553)+2553)%2553;
            qs[i][j] = (dp[i][j]+qs[i-1][j])%2553;
        }
    }
    for(i=1;i<=n;i++)
        ans += (dp[n][i]*dp[n][i]*dp[n][i]);
    printf("%lld\n",ans%2553);
    return 0;
}
/*
5 2
GOLF
JUMP
FOG
BEAM
TAN
*/
