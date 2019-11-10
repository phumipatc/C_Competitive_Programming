/*
    TASK :
    AUTHOR : Boss
    SCHOOL : RYW
    LANG : C
*/
#include<stdio.h>
int main()
{
    int q,n,i,j;
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(i==0 || j==0 || i==n/2 || (j==n-1 && i<=n/2) )
                    printf("*");
                else
                    printf("-");
            }
            printf("-");
            for(j=0;j<n;j++)
            {
                if(i==0 || j==0 || i==n-1 || j==n-1)
                    printf("*");
                else
                    printf("-");
            }
            printf("-");
            for(j=0;j<n;j++)
            {
                if(i==0 || i==n-1 || i==n/2 || (j==0 && i<=n/2) || (j==n-1 && i>n/2) )
                    printf("*");
                else
                    printf("-");
            }
            printf("-*");
            if(i>=1)
            {
                for(j=1;j<i;j++)
                    printf("-");
                printf("*");
            }
            if(i<=n-2)
            {
                for(j=n-2;j>i;j--)
                    printf("-");
            }s
            if(i!=n-1)
                printf("*");
            printf("\n");
        }
    }
    return 0;
}
