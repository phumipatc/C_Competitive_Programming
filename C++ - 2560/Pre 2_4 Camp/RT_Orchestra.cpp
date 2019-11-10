/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long day[110];
long long dp[110][510];
int main()
{
    long long n,m,k,ans,temp,num;
    scanf("%lld %lld %lld",&n,&m,&k);
    for(int i=1;i<=n;i++){
        scanf("%lld",&num);
        day[num]++;
    }
    for(int i=1;i<=m;i++)
        for(int j=0;j<=k;j++)
            dp[i][j] = 1e10;
    for(int i=1;i<=m;i++){
        dp[i][0] = dp[i-1][0]+day[i]*(day[i]+1)/2;
        for(int j=1;j<=k;j++){
            dp[i][j] = dp[i-1][j]+day[i]*(day[i]+1)/2;
            for(int l=j-1;l>=0;l--){
                temp = day[i]/(j-l+1);
                dp[i][j] = min(dp[i][j],dp[i-1][l]+(j-l+1)*(temp+1)*temp/2+(temp+1)*(day[i]-(j-l+1)*temp));
            }
        }
    }
    printf("%lld\n",dp[m][k]);
    return 0;
}


