/*
    TASK:
    AUTHOR:
    SCHOOL:RYW
    LANG: C
*/
#include<stdio.h>
int main()
{
    int x,a,b,b1,c,c1,d,d1,e,e1,f;
    scanf("%d",&x);
    a=x-60*(x/60);x=x/60;
    b=x-60*(x/60);x=x/60;
    c=x-24*(x/24);x=x/24;
    d=x-30*(x/30);x=x/30;
    e=x-12*(x/12);x=x/12;
    f=x;
    printf("%d",f);
        if(f>1){
            printf("Years ");
        }else{
            printf("Year ");
        }
    printf("%d",e);
        if(e>1){
            printf("Months ");
        }else{
            printf("Month ");
        }
    printf("%d",d);
        if(d>1){
            printf("Days ");
        }else{
            printf("Day ");
        }
    printf("%d",c);
        if(c>1){
            printf("Hours ");
        }else{
            printf("Hour ");
        }
    printf("%d",b);
        if(b>1){
            printf("Minutes ");
        }else{
            printf("Minute ");
        }
    printf("%d",a);
        if(a>1){
            printf("Seconds ");
        }else{
            printf("Second ");
        }
return 0;
}
