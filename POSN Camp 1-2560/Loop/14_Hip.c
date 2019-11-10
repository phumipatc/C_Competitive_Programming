/*
    TASK :
    AUTHOR : Boss
    SCHOOL : RYW
    LANG : C
*/
#include<stdio.h>
int main()
{
    int n,i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        for(j=i;j<n-1;j++)
            printf(".");
        printf("*");
        for(j=0;j<i;j++)
            printf("-");
        for(j=1;j<i;j++)
            printf("-");
        if(i!=0)
            printf("*");
        for(j=i;j<n-1;j++)
            printf(".");
        for(j=i+1;j<n-1;j++)
            printf(".");
        if(i!=n-1)
            printf("*");
        for(j=0;j<i;j++)
            printf("-");
        for(j=1;j<i;j++)
            printf("-");
        if(i!=0)
            printf("*");
        for(j=i;j<n-1;j++)
            printf(".");
        printf("\n");
    }
    for(i=0;i<n+n-2;i++)
    {
        for(j=0;j<=i;j++)
            printf(".");
        printf("*");
        for(j=i;j<n+n-3;j++)
            printf("-");
        for(j=i;j<n+n-4;j++)
            printf("-");
        if(i!=n+n-3)
            printf("*");
        for(j=0;j<=i;j++)
            printf(".f");
        printf("\n");
    }
    return 0;
}
