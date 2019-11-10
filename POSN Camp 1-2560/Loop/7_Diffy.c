/*
    TASK :
    AUTHOR : Boss
    SCHOOL : RYW
    LANG : C
*/
#include<stdio.h>
int main()
{
    int a,b,c,d,k,ch=0;
    scanf("%d %d %d %d",&a,&b,&c,&d);
    printf("%d %d %d %d\n",a,b,c,d);
    while(a!=0 || b!=0 || c!=0 || d!=0)
    {
        k=a;
        a=abs(a-b);
        b=abs(b-c);
        c=abs(c-d);
        d=abs(k-d);
        ch++;
        printf("%d %d %d %d\n",a,b,c,d);
    }
    printf("%d",ch);
    return 0;
}
