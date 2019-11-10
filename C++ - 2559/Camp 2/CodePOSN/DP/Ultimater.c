#include<stdio.h>
int a[1010][1010];
int main()
{
    int n,m,ans = 0,test,ch = 1;
    int k = 1,i,j;
    char tmp;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            scanf(" %c",&tmp);
            if(tmp=='#')
                a[i][j] = 0;
            else
                a[i][j] = 1,ch=2;

            a[i][j] += a[i-1][j] + a[i][j-1] - a[i-1][j-1];
        }
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(a[i][j]==1)
            {
                a[i][j] += min(a[i][j],min(a[i-1][j],a[i][j-1]));
                ans = max(ans,a[i][j]);
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
