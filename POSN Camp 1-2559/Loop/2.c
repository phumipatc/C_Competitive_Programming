/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C
*/
#include<stdio.h>
int main()
{
    int x,y,n;
    scanf("%d %d",&x,&y);
    for(n=y;n>=x;n--){
        if(n%4==0 && n%100!=0){
            printf("%d\n",n);
        }else if(n%400==0){
            printf("%d\n",n);
        }
    }
return 0;
}
