/*
    TASK :
    AUTHOR : Boss
    SCHOOL : RYW
    LANG : C
*/
#include<stdio.h>
#include<math.h>
int main()
{
    int n,i;
    scanf("%d",&n);
    for(i=2;i<n;i++)
    {
        if(n%i==0)
        {
            printf("Not a specific number\n");
            return 0;
        }
    }
    printf("A specific number\n");
    return 0;
}
