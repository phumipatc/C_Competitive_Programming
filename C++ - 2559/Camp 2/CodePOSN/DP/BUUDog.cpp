#include<bits/stdc++.h>
using namespace std;
long long c[60][60];
int main()
{
    int n,m,q,a,b;
    scanf("%d %d %d",&n,&m,&q);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            c[i][j] = -1;
    while(q--)
    {
        scanf("%d %d",&a,&b);
        c[a][b] = 0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(i==1&&j==1)
                c[i][j] = 1;
            else if(c[i][j]!=0)
                    c[i][j] = c[i-1][j]+c[i][j-1];
        }
    }
    printf("%lld\n",c[n][m]);
    return 0;
}
