/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C
*/
#include<stdio.h>
int main()
{
    int j,q,a,b,i,sum;
    scanf("%d",&q);
    for(j=0;j<q;j++){
        scanf("%d %d",&a,&b);
        for(i=a;i<=b;i+=2){
            sum = i+=(i+1);
        }
    }
    printf("%d",sum);
return 0;
}
