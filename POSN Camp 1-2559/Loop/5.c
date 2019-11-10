/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C
*/
#include<stdio.h>
int main()
{
    int a,b,c,n,i,x;
    scanf("%d %d %d %d",&a,&b,&c,&n);
    for(i=1;i<=n;i++){
        scanf("%d",&x);
        if(x<a){
            printf("no\n");
        }else if((x-a)%(b+c)<=b){
            printf("yes\n");
        }else if((x-a)%(b+c)>b){
            printf("no\n");
        }
    }
return 0;
}
