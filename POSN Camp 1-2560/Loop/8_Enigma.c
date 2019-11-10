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
            printf("+");
        for(j=0;j<=i;j++)
            printf("0");
        for(j=0;j<i;j++)
            printf("0");
        for(j=i;j<n-1;j++)
            printf("+");
        printf("\n");
    }
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<=i;j++)
            printf("+");
        for(j=i;j<n-1;j++)
            printf("0");
        for(j=i;j<n-2;j++)
            printf("0");
        for(j=0;j<=i;j++)
            printf("+");
        printf("\n");
    }
    return 0;
}
