/*
    TASK:Fluctuate
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C
*/
#include<stdio.h>
int main()
{
    int i,n,m[100000],min,max;
    min=10000000;
    max=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&m[i]);
    }
    for(i=0;i<n;i++){
        if(m[i]>m[i+1]){
        if(m<min){
            min=m;
        }
        if(m>max){
            max=m;
        }
        }
    }
    printf("%d",max-min);
return 0;
}
