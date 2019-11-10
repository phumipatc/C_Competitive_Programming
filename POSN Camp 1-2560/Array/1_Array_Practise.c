/*
    TASK :
    AUTHOR : Boss
    SCHOOL : RYW
    LANG : C
*/
#include<stdio.h>
int a[1200];
int main()
{
    int n,i,k,c=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    scanf("%d",&k);
    for(i=n-1;i>=0;i--)
    {
        printf("%d ",a[i]);
        if(a[i]==k)
        {
            c++;
        }
    }
    printf("\n%d",c);
    return 0;
}
