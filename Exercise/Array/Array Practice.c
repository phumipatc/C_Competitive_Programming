/*
    TASK:
    AUTHOR:
    SCHOOL:RYW
    LANG: C
*/
#include<stdio.h>
int main()
{
    int a[1010],n,i,k,count=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }scanf("%d",&k);
    for(i=n-1;i>=0;i--){
        printf("%d ",a[i]);
    }printf("\n");
    for(i=0;i<n;i++){
        if(a[i]==k){
            count++;
        }
    }printf("%d\n",count);
return 0;
}
