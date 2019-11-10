/*
    TASK :
    AUTHOR : Boss
    SCHOOL : RYW
    LANG : C++
*/
#include<bits/stdc++.h>
using namespace std;
long longdp[105][10100];
int main()
{
    long longn,i,p,w,m,j;
    scanf("%lld %lld",&n,&m);
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
