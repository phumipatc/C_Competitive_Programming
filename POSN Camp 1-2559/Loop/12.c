/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    int n,m,i,j;
    scanf("%d %d",&n,&m);
    for(i=1;i<n;i++){
        for(j=n-i;j>0;j--){
            printf("-");
        }
        printf("*");
        for(j=i;j;)
    }
return 0;
}

