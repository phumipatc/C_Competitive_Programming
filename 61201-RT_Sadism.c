#include<bits/stdc++.h>
using namespace std;
#define N 1005
char str[N][N];
long long dpl[N][N];
long long dpr[N][N];
long long qsl[N][N];
long long qsr[N][N];
long long dpcol[N][N];
long long dprow[N][N];
int main()
{
    long long n,m,ansm=0,anss=0;
    scanf("%lld %lld",&n,&m);
    for(long long i=1;i<=n;i++)
    {
        scanf(" %s",str[i]+1);
        for(long long j=1;j<=m;j++)
        {
            dpcol[i][j]=dpcol[i-1][j]+qsl[i-1][j]-qsl[i-1][j-1];
            dprow[i][j]=dprow[i][j-1]+qsl[i][j-1]-qsl[i-1][j-1];
            qsl[i][j]=qsl[i-1][j]+qsl[i][j-1]-qsl[i-1][j-1]+(str[i][j]=='M');
            dpl[i][j]=dpl[i-1][j-1]+dpcol[i][j]+dprow[i][j]+qsl[i-1][j-1];
            if(str[i][j]=='M')  ansm+=dpl[i][j];
        }
        for(long long j=m;j>=1;j--)
        {
            dprow[i][j]=dprow[i][j+1]+qsr[i][j+1]-qsr[i-1][j+1];
            qsr[i][j]=qsr[i-1][j]+qsr[i][j+1]-qsr[i-1][j+1]+(str[i][j]=='M');
            dpr[i][j]=dpr[i-1][j+1]+dpcol[i][j]+dprow[i][j]+qsr[i-1][j+1];
            if(str[i][j]=='M')  ansm+=dpr[i-1][j+1]+qsr[i-1][j+1];
        }
    }
    for(long long i=1;i<=n;i++)
    {
        for(long long j=1;j<=m;j++)
        {
            dpcol[i][j]=dpcol[i-1][j]+qsl[i-1][j]-qsl[i-1][j-1];
            dprow[i][j]=dprow[i][j-1]+qsl[i][j-1]-qsl[i-1][j-1];
            qsl[i][j]=qsl[i-1][j]+qsl[i][j-1]-qsl[i-1][j-1]+(str[i][j]=='S');
            dpl[i][j]=dpl[i-1][j-1]+dpcol[i][j]+dprow[i][j]+qsl[i-1][j-1];
            if(str[i][j]=='S')  anss+=dpl[i][j];
        }
        for(long long j=m;j>=1;j--)
        {
            dprow[i][j]=dprow[i][j+1]+qsr[i][j+1]-qsr[i-1][j+1];
            qsr[i][j]=qsr[i-1][j]+qsr[i][j+1]-qsr[i-1][j+1]+(str[i][j]=='S');
            dpr[i][j]=dpr[i-1][j+1]+dpcol[i][j]+dprow[i][j]+qsr[i-1][j+1];
            if(str[i][j]=='S')  anss+=dpr[i-1][j+1]+qsr[i-1][j+1];
        }
    }
    printf("%lld %lld\n",ansm,anss);
    return 0;
}
