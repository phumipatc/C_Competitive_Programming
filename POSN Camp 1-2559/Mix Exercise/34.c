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
    int n,i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        for(j=n-i-1;j>0;j--){
            printf(".");
        }printf("*");
        if(i>=1){
            for(j=0;j<i;j++){
                printf("-");
            }
        }
        if(i>=2){
            for(j=0;j<i-1;j++){
                printf("-");
            }
        }
        if(i>0)
            printf("*");
        for(j=n-i-1;j>0;j--){
            printf(".");
        }
        printf("\n");
    }
return 0;
}
