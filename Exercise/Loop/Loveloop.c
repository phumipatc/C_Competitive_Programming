/*
    TASK:
    AUTHOR:
    SCHOOL:RYW
    LANG: C
*/
#include<stdio.h>
#include<math.h>
int main()
{
   int x,i,j;

    scanf("%d",&x);
    for(i=1;i<=x;i++){
       for(j=1;j<=x;j++){
        printf("%d ",i+j-1);
    }
    printf("\n");
    }
    for(i=1;i<=x;i++){
       for(j=1;j<=x;j++){
        printf("%d ",((i+j-2)%x)+1);
    }
    printf("\n");
    }

return 0;
}
