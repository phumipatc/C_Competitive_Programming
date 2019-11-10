/*
    TASK :
    AUTHOR : Boss
    SCHOOL : RYW
    LANG : C
*/
#include<stdio.h>
int main()
{
    int p,i,h1,h2,ch1=0,ch2=0,n;
    scanf("%d",&p);
    h1=h2=p;
    for(i=0;i<2*p;i++)
    {
        scanf("%d",&n);
        if(n%2==0)
        {
            ch1++;
            ch2=0;
            if(ch1<3)
                h2--;
            else
                h2-=3;
        }
        else
        {
            ch2++;
            ch1=0;
            if(ch2<3)
                h1--;
            else
                h1-=3;
        }
        if(h1<=0)
        {
            printf("1\n%d",n);
            return 0;
        }
        else if(h2<=0)
        {
            printf("0\n%d",n);
            return 0;
        }
    }
    return 0;
}
