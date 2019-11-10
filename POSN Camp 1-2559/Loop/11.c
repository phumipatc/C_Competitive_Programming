/*
    TASK: Hip
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL: RYW
    LANG: C
            */
#include<stdio.h>
int main()
{
int b,i,j,x,n;
    scanf("%d",&n);

    for(i=0;i<n;i++){
        for(j=n-1;j>i;j--)
            printf(".");
            printf("*");
        for(j=0;j<2*i-1;j++)
            printf("-");
            if(i!=0)
                printf("*");
        for(j=0;j<2*n-3-2*i;j++)
            printf(".");
            if(i!=n-1)
                printf("*");
        for(j=0;j<2*i-1;j++)
            printf("-");
            if(i!=0)
                printf("*");
        for(j=n-1;j>i;j--)
            printf(".");

        printf("\n");
    }
    for(i=0;i<2*n-2;i++){
        for(j=0;j<=i;j++)
            printf(".");
            printf("*");
        for(j=0;j<4*n-7-2*i;j++)
            printf("-");
            if(i!=2*n-3)
                printf("*");
        for(j=0;j<=i;j++)
            printf(".");

        printf("\n");
    }

        return 0;
}
