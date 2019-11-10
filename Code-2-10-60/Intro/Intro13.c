/*
    Task :
    Author : Boss
    School : RYW
    Language : C
*/
#include<stdio.h>
int main()
{
    int a,b,c,d,k,sum=0;
    scanf("%d %d %d %d",&a,&b,&c,&d);
    printf("%d %d %d %d\n",a,b,c,d);
    while(a!=0 || b!=0 || c!=0 || d!=0){
        k=a;
        a=abs(a-b);
        b=abs(b-c);
        c=abs(c-d);
        d=abs(d-k);
        printf("%d %d %d %d\n",a,b,c,d);
        sum++;
    }
    printf("%d",sum);
    return 0;
}
