/*
    Task : Practise03
    Author :
    School :
    Language :
*/
#include<stdio.h>
int main()
{
    int a,b,i;
    scanf("%d %d",&a,&b);
    if(a>=b)
        for(i=a;i>=b;i--)
            printf("%d\n",i);
    else if(b>a)
        for(i=a;i<=b;i++)
            printf("%d\n",i);
    return 0;
}
