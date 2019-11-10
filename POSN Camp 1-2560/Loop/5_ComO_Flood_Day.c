/*
    TASK :
    AUTHOR : Boss
    SCHOOL : RYW
    LANG : C
*/
#include<stdio.h>
int main()
{
    int q,n,l,i,ch=0;
    scanf("%d",&q);
    for(i=0;i<q;i++)
    {
        scanf("%d",&n);
        if(q!=0)
        {
            if(n>=80 || (n>=20 && n-l>=10))
                ch++;
        }
        l=n;
    }
    printf("%d",ch);
    return 0;
}
/*
8 60 5 19 40 90 85 50 60
*/
