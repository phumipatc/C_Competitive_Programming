/*
    TASK :
    AUTHOR : Boss
    SCHOOL : RYW
    LANG : C
*/
#include<stdio.h>
int main()
{
    int a,b,i,k,n,c0,c1,c2,c3,c4,c5,c6,c7,c8,c9;
    scanf("%d %d",&a,&b);
    c0=c1=c2=c3=c4=c5=c6=c7=c8=c9=0;
    for(i=a;i<=b;i++)
    {
        n=i;
        while(n>0)
        {
            k=n%10;
            switch(k)
            {
                case 0:c0++; break;
                case 1:c1++; break;
                case 2:c2++; break;
                case 3:c3++; break;
                case 4:c4++; break;
                case 5:c5++; break;
                case 6:c6++; break;
                case 7:c7++; break;
                case 8:c8++; break;
                case 9:c9++; break;
            }
            n=n/10;
        }
    }
    printf("%d %d %d %d %d %d %d %d %d %d",c0,c1,c2,c3,c4,c5,c6,c7,c8,c9);
    return 0;
}
