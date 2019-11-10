#include<stdio.h>
#include<math.h>
int main()
{
   int m,n,k,i,j;
   scanf("%d %d",&n,&m);
   int a[n][m];
   for(i=0;i<=n-1;i++)
        for(j=0;j<=m-1;j++)
        scanf("%d",&a[i][j]);
   for(i=0;i<=n-1;i++)
        for(j=0;j<=m-1;j++)
            printf("%d ",a[i][j]);
    printf("\n");
    for(i=n-1;i>=0;i--)
        for(j=m-1;j>=0;j--)
            printf("%d ",a[i][j]);
    printf("\n");
    for(j=0;j<=m-1;j++)
        for(i=0;i<=n-1;i++)
            printf("%d ",a[i][j]);
    printf("\n");
    for(j=m-1;j>=0;j--)
        for(i=n-1;i>=0;i--)
            printf("%d ",a[i][j]);
return 0;
}
