/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int a[100100];
int main()
{
    int n,i,j,q,sum,x,y;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    scanf("%d",&q);
    for(i=0;i<q;i++){
        scanf("%d %d",&x,&y);
        for(j=x+1;j<y;j++){
            sum=a[j]+a[j-1];
        }
        printf("%d",sum);
    }
return 0;
}
