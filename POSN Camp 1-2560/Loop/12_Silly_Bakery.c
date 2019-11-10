/*
    TASK :
    AUTHOR : Boss
    SCHOOL : RYW
    LANG : C
*/
#include<stdio.h>
int main()
{
    int a,b,c,d,e,x1,x2,x3,x4,x5,sum=0,piece=0,n;
    scanf("%d",&n);
    a=b=c=d=e=0;
    while(n--)
    {
        scanf("%d %d %d %d %d",&x1,&x2,&x3,&x4,&x5);
        a+=x1;
        b+=x2;
        c+=x3;
        d+=x4;
        e+=x5;
    }
    while(a!=0 || b!=0 || c!=0 || d!=0 || e!=0)
    {
        if(piece>=8 && a>=1)
        {
            a--;
            piece-=8;
        }
        else if(piece>=6 && b>=1)
        {
            b--;
            piece-=6;
        }
        else if(piece>=4 && c>=1)
        {
            c--;
            piece-=4;
        }
        else if(piece>=2 && d>=1)
        {
            d--;
            piece-=2;
        }
        else if(piece>=1 && e>=1)
        {
            e--;
            piece--;
        }
        else
        {
            piece=8;
            sum++;
        }
    }
    printf("%d",sum);
    return 0;
}
/*
3
1 0 1 0 1
0 1 0 1 0
0 1 0 0 0
*/
