/*
    TASK :
    AUTHOR : Boss
    SCHOOL : RYW
    LANG : C
*/
#include<stdio.h>
int main()
{
    int a,b,i;
    scanf("%d %d",&a,&b);
    for(i=b;i>=a;i--){
        if((i%4==0 && i%100!=0) || i%400==0)
            printf("%d\n",i);
    }
    return 0;
}
