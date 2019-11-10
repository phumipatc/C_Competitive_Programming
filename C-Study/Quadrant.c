/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C
*/
#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    n=n%360;
    if(n>270 || (n<0 && n>-90))
        printf("4\n");
    else if(n==270 || n==-90)
        printf("y-axis\n");
    else if(n>180 || (n<-90 && n>-180))
        printf("3\n");
    else if(abs(n)==180)
        printf("x-axis\n");
    else if(n>90 || (n<-180 && n>-270))
        printf("2\n");
    else if(n==90 || n==-270)
        printf("y-axis\n");
    else if(n>0 || (n<-270))
        printf("1\n");
    else if(n==0)
        printf("x-axis\n");
return 0;
}
