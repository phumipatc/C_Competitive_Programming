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
    int a,b,i,j;
    scanf("%d %d",&a,&b);
    for(i=1;i<a;i++){
        for(j=a-i;j>0;j--){
            printf("-");
        }
        printf("\n");
    }
return 0;
}
