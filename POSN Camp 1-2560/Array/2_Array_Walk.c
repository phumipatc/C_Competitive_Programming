/*
    TASK :
    AUTHOR : Boss
    SCHOOL : RYW
    LANG : C
*/
#include<stdio.h>
int a[50][50];
int main()
{
    int n,m,i,j;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
        scanf("%d",&a[i][j]);
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            printf("%d ",a[i][j]);
    printf("\n");
    for(i=n-1;i>=0;i--)
        for(j=m-1;j>=0;j--)
            printf("%d ",a[i][j]);
    printf("\n");
    for(j=0;j<m;j++)
        for(i=0;i<n;i++)
            printf("%d ",a[i][j]);
    printf("\n");
    for(j=m-1;j>=0;j--)
        for(i=n-1;i>=0;i--)
        printf("%d ",a[i][j]);
    return 0;
}
