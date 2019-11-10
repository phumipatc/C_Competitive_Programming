/*
    TASK:Permutation
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C
*/
#include<stdio.h>
#include<stdlib.h>
int a,b,c,d,x[20],y[20];
void permu(int z){
    int i;
    if(z==b){
        d++;
        if(d==c){
            for(i=0;i<b-1;i++)
                printf("%d ",y[i]);
            printf("%d\n",y[i]);
            exit(0);
        }
    }else{
        for(i=0;i<a;i++){
            if(x[i]!=-1){
                x[i]=-1;
                y[z]=i+1;
                permu(z+1);
                x[i]=0;
            }
        }
    }
}
int main()
{
    scanf("%d %d %d",&a,&b,&c);
    d=0;
    permu(0);
return 0;
}
