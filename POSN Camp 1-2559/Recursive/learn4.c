/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C
*/
#include<stdio.h>
#include<math.h>
int g(int a,int b){
    if(a==1){
        return 1;
    }else{
        return g(a-1,b)+pow(a,b);
    }
}
int main()
{
    int a,b,x;
    scanf("%d %d",&a,&b);
    x=g(a,b);
    printf("%d",x);
return 0;
}
