/*
    TASK :
    AUTHOR : Boss
    SCHOOL : RYW
    LANG : C++
*/
#include<bits/stdc++.h>
using namespace std;
long long dp[105][1000010];
int main()
{
    long long n,i,p,w,m,j;
    scanf("%lld %lld",&n,&m);
    m*=2;
    for(i=1;i<=n;i++){
        scanf("%lld %lld",&p,&w);
        for(j=0;j<w;j++)
            dp[i][j]=dp[i-1][j];
        for(j=w;j<=m;j++)
            dp[i][j]=max(dp[i-1][j],p+dp[i-1][j-w]);
    }
    printf("%lld\n",dp[n][m]);
    return 0;
}
