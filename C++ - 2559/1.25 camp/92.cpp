/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<stdio.h>
typedef struct{
    int f,w;
}S;
S s[100100];
int main()
{
    int q,f,w,top=0;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&w,&f);
        while(top>0 && w>s[top-1].w){
            printf("%d\n",s[top-1].f);
            top--;
        }
        s[top].w=w;
        s[top].f=f;
        top++;
    }
return 0;
}
