/*
    TASK :
    AUTHOR : Boss
    SCHOOL : RYW
    LANG : C
*/
#include<stdio.h>
int main()
{
    int n,min,max,i=9;
    scanf("%d",&n);
    min=max=n;
    while(i--)
    {
        scanf("%d",&n);
        if(max<n)
            max=n;
        if(min>n)
            min=n;
    }
    printf("MIN : %d\nMAX : %d\n",min,max);
    return 0;
}
