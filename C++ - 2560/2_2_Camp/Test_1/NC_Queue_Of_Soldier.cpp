/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
long long ncr[52000][1020],mic[50100][1200],a[52000],c[1050];
int main()
{
    long long i,n,j,countt=0,k,x;
    for(i=0;i<=51000;i++)
        ncr[i][0]=1;
    for(i=1;i<=51000;i++){
        for(j=1;j<=min((int)i,1010);j++){
            ncr[i][j]=ncr[i-1][j-1]+ncr[i-1][j];
            ncr[i][j]%=mod;
        }
    }
    scanf("%lld %lld",&n,&k);
    for(i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    for(i=1;i<=n;i++){
        if(a[i]!=a[i-1])    countt++;
        c[countt]++;
    }
    for(i=1;i<=countt;i++)
        c[i]+=c[i-1];
    for(i=0;i<=50000;i++)
        mic[i][0]=1;
    for(i=0;i<=1000;i++)
        mic[0][i]=1;
    for(i=1;i<=countt;i++){
        for(j=1;j<=k;j++){
            for(x=0;x<=min(j,c[i]-c[i-1]);x++){
                if(c[i-1]-1+x<0)    continue;
                mic[i][j]+=mic[i-1][j-x]*ncr[c[i-1]-1+x][x];
                mic[i][j]%=mod;
            }
        }
    }
    printf("%lld\n",mic[countt][k]);
    return 0;
}


