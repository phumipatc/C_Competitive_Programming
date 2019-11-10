/*
    TASK :
    AUTHOR : Boss
    SCHOOL : RYW
    LANG : C
*/
#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    n=n%360;
    if(n>0)
    {
        if(n<90)
        {
            printf("1");
        }
        else if(n==90 || n==270)
        {
            printf("y-axis");
        }
        else if(n<180)
        {
            printf("2");
        }
        else if(n==180)
        {
            printf("x-axis");
        }
        else if(n<270)
        {
            printf("3");
        }else if(n<360){
            printf("4");
        }
    }
    else if(n<0)
    {
        if(n>-90)
        {
            printf("4");
        }
        else if(n==-90 || n==-270)
        {
            printf("y-axis");
        }
        else if(n>-180)
        {
            printf("3");
        }
        else if(n==-180)
        {
            printf("x-axis");
        }
        else if(n>-270)
        {
            printf("2");
        }
        else if(n>-360)
        {
            printf("1");
        }
    }
    else
    {
        printf("x-axis");
    }
    return 0;
}
