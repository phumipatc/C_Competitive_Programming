/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C
*/
#include<stdio.h>
int main()
{
    int n,i,j;
    scanf("%d",&n);
    for(i=0;i<n+(n-1);i++)
        printf("X");
            printf("\n");
    for(i=0;i<(n-1)/2;i++){
        for(j=0;j<(n-1)/2;j++){
        printf("-");
    }
    printf("*\n");
    }
return 0;
}
