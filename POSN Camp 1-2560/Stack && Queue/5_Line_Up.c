/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct data{
    int id,money;
};
typedef struct data data;
data q[210000];
int main()
{
    char a;
    int front=0,x=0,now=-1;
    while(1){
        scanf(" %c",&a);
        if(a=='E')  break;
        if(a=='A'){
            scanf("%d %d",&q[x].id,&q[x].money);
            x++;
        }else if(a=='G'){
            scanf("%d",&now);
        }
        if(now!=-1){
            while(front<x){
                if(q[front].money>=now){
                    printf("%d %d\n",q[front].id,q[front].money-now);
                    front++;
                    now=-1;
                    break;
                }
                front++;
            }
        }
    }
return 0;
}
