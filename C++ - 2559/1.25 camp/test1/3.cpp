/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<stdio.h>
int main()
{
    int q,i,t,va=0,vb=0,vc=0;
    scanf("%d",&q);
    for(i=0;i<q;i++){
        scanf("%d",&t);
        if(i==0){
            printf("A\n");
            va+=t;
        }else{
            if(va<=vb && va<=vc){
                printf("A\n");
                va+=t;
            }else if(vb<va && vb<=vc){
                printf("B\n");
                vb+=t;
            }else if(vc<va && vc<vb){
                printf("C\n");
                vc+=t;
            }
        }
    }
return 0;
}
