/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C
*/
#include<stdio.h>
int main()
{
    int a=0,i,n,x,old;
    scanf("%d",&n);
    old=300;
    for(i=1;i<=n;i++){
        scanf("%d",&x);

        if(x>=80){
            a++;
            old=x;
        }else if(x>=20 && (x-old)>=10){
            a++;
            old=x;
        }else{
            old=x;
        }
    }
    printf("%d",a);
return 0;
}
