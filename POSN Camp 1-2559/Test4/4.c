/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int x[10];
char y[10];
int main()
{
    int q,a;
    scanf("%d",&q);
    for(i=0;i<q;i++){
        scanf("%d",&a);
        for(j=0;j<a;j++){
            scanf("%d",x[j]);
        }
        for(j=0;j<a;j++){
            scanf("%c",y[j]);
            if(y[j]=='-')
                x[j]*(-1);

        }
    }
return 0;
}
