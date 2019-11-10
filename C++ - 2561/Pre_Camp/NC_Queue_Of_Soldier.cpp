/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
long long nCr[52000][1020],dp[50100][1200],a[52000],num[1050];
int main()
{
    long long n,k,countt = 0;
    for(long long i=0;i<=51000;i++)
        nCr[i][0] = 1;
    for(long long i=1;i<=51000;i++){
        for(long long j=1;j<=min(i,1010ll);j++){
            nCr[i][j] = nCr[i-1][j-1]+nCr[i-1][j];
            nCr[i][j]%=MOD;
        }
    }
    scanf("%lld %lld",&n,&k);
    for(long long i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    for(long long i=1;i<=n;i++){
        if(a[i]!=a[i-1])    countt++;
        num[countt]++;
    }
    for(long long i=1;i<=countt;i++)    num[i]+=num[i-1];
    for(long long i=0;i<=50000;i++)     dp[i][0] = 1;
    for(long long i=0;i<=1000;i++)      dp[0][i] = 1;
    for(long long i=1;i<=countt;i++){
        for(long long j=1;j<=k;j++){
            for(long long kk = 0;kk<=min(j,num[i]-num[i-1]);kk++){
                if(num[i-1]+kk-1<0) continue;
                dp[i][j]+=dp[i-1][j-kk]*nCr[num[i-1]-1+kk][kk];
                dp[i][j]%=MOD;
            }
        }
    }
    printf("%lld\n",dp[countt][k]);
    return 0;
}


