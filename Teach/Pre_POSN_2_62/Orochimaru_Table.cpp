#include<bits/stdc++.h>
using namespace std;
long long mic[105][105],nei[3];
vector<long long> a[105][105],b;
int main()
{
    long long n,m,i,j,mem,ma,k;
    scanf("%lld %lld",&n,&m);
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            scanf("%lld",&mic[i][j]);
    for(i=0;i<n;i++)
        a[i][0].push_back(i);
    for(j=1;j<m;j++)
    {
        for(i=0;i<n;i++)
        {
            nei[0]=(i-1+n)%n;
            nei[1]=i;
            nei[2]=(i+1)%n;
            ma=__LONG_LONG_MAX__;
            for(k=0;k<3;k++)
            {
                if(ma>mic[nei[k]][j-1])
                {
                    ma=mic[nei[k]][j-1];
                    b=a[nei[k]][j-1];
                }
                else if(ma==mic[nei[k]][j-1]&&b>a[nei[k]][j-1])
                    b=a[nei[k]][j-1];
            }
            mic[i][j]+=ma;
            b.push_back(i);
            a[i][j]=b;
        }
    }
    ma=__LONG_LONG_MAX__;
    for(i=0;i<n;i++)
    {
        if(mic[i][m-1]<ma)
        {
            ma=mic[i][m-1];
            b=a[i][m-1];
        }
        else if(mic[i][m-1]==ma&&b>a[i][m-1])
            b=a[i][m-1];
    }
    printf("%lld\n",ma);
    for(i=0;i<b.size();i++)
        printf("%lld ",b[i]+1);
    return 0;
}
