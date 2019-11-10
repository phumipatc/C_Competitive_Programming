/*
    TASK:
    AUTHOR:
    SCHOOL:RYW
    LANG: C
*/
#include<stdio.h>
#include<math.h>
int main()
{
   int X,Y,a;

    scanf("%d %d",&X,&Y);
    for(a=Y;a>=X;a--){
        if(a%4==0&&a%100!=0){
        printf("%d\n",a);
    }else if(a%400==0){
        printf("%d\n",a);
    }
    }
return 0;
}
