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
    srand(time(NULL));
    int n,q=rand()%100;
    while(1)
    {
        scanf("%d",&n);
        if(n>q)
        {
            printf("more\n");
        }
        else if(n<q)
        {
            printf("less\n");
        }
        else
        {
            printf("O.K.\n");
            return 0;
        }
    }
    return 0;
}
