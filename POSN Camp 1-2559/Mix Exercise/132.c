/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int a[300];
int main()
{
    int n,i,r,h,j,l,o=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d %d %d",&l,&h,&r);
        for(j=l;j<r;j++){
            if(h>a[j]){
                a[j]=h;
            }
        }
    }
    for(i=0;i<260;i++){
        if(a[i]!=o)
            printf("%d %d ",i,a[i]);
            o=a[i];
    }
return 0;
}
