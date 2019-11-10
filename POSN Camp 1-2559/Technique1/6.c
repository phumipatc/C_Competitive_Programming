/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C
*/
#include<stdio.h>
int main()
{
    int p,i,count=0;
    scanf("%d",&p);
    for(i=1;i<=p;i++){
        if(p%i==0){
            count++;
        }
    }
    printf("%d",count);
return 0;
}
