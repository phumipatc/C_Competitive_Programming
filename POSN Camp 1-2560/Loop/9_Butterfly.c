/*
    TASK :
    AUTHOR : Boss
    SCHOOL : RYW
    LANG : C
*/
#include<stdio.h>
int main()
{
    char a;
    int n,i,j;
    scanf("%c %d",&a,&n);
    for(i=0;i<n/2;i++)
    {
        for(j=0;j<=i;j++)
            printf("%c",a);
        for(j=i+1;j<n/2;j++)
            printf(".");
        for(j=i+1;j<n/2;j++)
            printf(".");
        for(j=0;j<=i;j++)
            printf("%c",a);
        printf("\n");
    }
    for(i=0;i<n/2-1;i++)
    {
        for(j=i+1;j<n/2;j++)
            printf("%c",a);
        for(j=0;j<=i;j++)
            printf(".");
        for(j=0;j<=i;j++)
            printf(".");
        for(j=i+1;j<n/2;j++)
            printf("%c",a);
        printf("\n");
    }
    return 0;
}
