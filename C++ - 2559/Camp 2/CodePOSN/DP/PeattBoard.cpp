#include<stdio.h>
int a[1100][1100];
int main()
{
    int n,m,q,x1,x2,y1,y2,i,j;
    scanf("%d %d %d",&m,&n,&q);
    while(q--)
    {
        scanf("%d %d %d %d",&y1,&x1,&y2,&x2);
        for(i = x1;i<=x2;i++)
            a[i][y1]++,a[i][y2+1]--;
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            a[i][j] += a[i][j-1];
            printf("%d",a[i][j]%2);
        }
        printf("\n");
    }
    return 0;
}
