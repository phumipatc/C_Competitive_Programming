/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long dp1[1010][1010],dp2[1010][1010],sums1[1010][1010],summ1[1010][1010],r1[1010][1010],c1[1010][1010],r2[1010][1010],c2[1010][1010];
long long summ2[1010][1010],sums2[1010][1010];
char mapp[1010][1010];
int main()
{
    long long n,m,i,j,sum1,sum2;
    scanf("%lld %lld",&n,&m);
    sum1 = sum2 = 0;
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            scanf(" %c",&mapp[i][j]);
            if(mapp[i][j]=='S'){
                sums1[i][j] = sums1[i-1][j] + sums1[i][j-1] - sums1[i-1][j-1] + 1;
                summ1[i][j] = summ1[i-1][j] + summ1[i][j-1] - summ1[i-1][j-1];
            }
            if(mapp[i][j]=='M'){
                summ1[i][j] = summ1[i-1][j] + summ1[i][j-1] - summ1[i-1][j-1] + 1;
                sums1[i][j] = sums1[i-1][j] + sums1[i][j-1] - sums1[i-1][j-1];
            }
            if(mapp[i][j]=='.'){
                sums1[i][j] = sums1[i-1][j] + sums1[i][j-1] - sums1[i-1][j-1];
                summ1[i][j] = summ1[i-1][j] + summ1[i][j-1] - summ1[i-1][j-1];
            }
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            dp1[i][j] = dp1[i-1][j-1] + r1[i-1][j-1] + c1[i-1][j-1] + summ1[i-1][j-1];
            r1[i][j] = r1[i][j-1] + summ1[i][j-1] - summ1[i-1][j-1];
            c1[i][j] = c1[i-1][j] + summ1[i-1][j] - summ1[i-1][j-1];
        }
    }
    for(i=1;i<=n;i++){
        for(j=m;j>=1;j--){
            if(mapp[i][j]=='M')
                summ2[i][j] = summ2[i-1][j] + summ2[i][j+1] - summ2[i-1][j+1] + 1;
            else
                summ2[i][j] = summ2[i-1][j] + summ2[i][j+1] - summ2[i-1][j+1];
        }
    }
    for(i=1;i<=n;i++){
        for(j=m;j>=1;j--){
            dp2[i][j] = dp2[i-1][j+1] + r2[i-1][j+1] + c2[i-1][j+1] + summ2[i-1][j+1];
            r2[i][j] = r2[i][j+1] + summ2[i][j+1] - summ2[i-1][j+1];
            c2[i][j] = c2[i-1][j] + summ2[i-1][j] - summ2[i-1][j+1];
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(mapp[i][j]=='M'){
                sum1 += dp1[i][j] + r1[i][j] + c1[i][j] + dp2[i][j];
            }
        }
    }
    //printf("%d\n",sum1);
    memset(dp1,0,sizeof dp1);
    memset(dp2,0,sizeof dp2);
    memset(r1,0,sizeof r1);
    memset(r2,0,sizeof r2);
    memset(c1,0,sizeof c1);
    memset(c2,0,sizeof c2);
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            dp1[i][j] = dp1[i-1][j-1] + r1[i-1][j-1] + c1[i-1][j-1] + sums1[i-1][j-1];
            r1[i][j] = r1[i][j-1] + sums1[i][j-1] - sums1[i-1][j-1];
            c1[i][j] = c1[i-1][j] + sums1[i-1][j] - sums1[i-1][j-1];
        }
    }
    for(i=1;i<=n;i++){
        for(j=m;j>=1;j--){
            if(mapp[i][j]=='S')
                sums2[i][j] = sums2[i-1][j] + sums2[i][j+1] - sums2[i-1][j+1] + 1;
            else
                sums2[i][j] = sums2[i-1][j] + sums2[i][j+1] - sums2[i-1][j+1];
        }
    }
    for(i=1;i<=n;i++){
        for(j=m;j>=1;j--){
            dp2[i][j] = dp2[i-1][j+1] + r2[i-1][j+1] + c2[i-1][j+1] + sums2[i-1][j+1];
            r2[i][j] = r2[i][j+1] + sums2[i][j+1] - sums2[i-1][j+1];
            c2[i][j] = c2[i-1][j] + sums2[i-1][j] - sums2[i-1][j+1];
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(mapp[i][j]=='S'){
                sum2 += dp1[i][j] + r1[i][j] + c1[i][j] + dp2[i][j];
            }
        }
    }
    printf("%lld %lld\n",sum1,sum2);
    return 0;
}
/*
4 5
M....
..S.M
SS..S
.M...
*/
