/*
    Task :
    Author : Boss
    School : RYW
    Language : C
*/
#include<stdio.h>
int main()
{
    int n,m,i;
    scanf("%d %d",&n,&m);
    for(i=m;i>=n;i--){
        if(i%400==0 || (i%100!=0 && i%4==0)){
            printf("%d\n",i);
        }
    }
    return 0;
}
