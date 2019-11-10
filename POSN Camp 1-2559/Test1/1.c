/*
    TASK:Marching Band
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C
*/
#include<stdio.h>
int main()
{
    int q,i,w,l,sum,multi;
    scanf("%d",&q);
    for(i=0;i<q;i++){
        scanf("%d %d",&w,&l);
        sum=(w*2)+(l*2);
        multi=w*l;
        printf("%d %d\n",sum,multi);
    }
return 0;
}
