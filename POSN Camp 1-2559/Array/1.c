/*
    TASK:
    AUTHOR:
    SCHOOL:RYW
    LANG: C
*/
#include<stdio.h>
int a[1200];
int main()
{
    int n,i,k,count=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }scanf("%d",&k);
    for(i=n-1;i>=0;i++){
        printf("%d",a[i]);
    }
    for(i=0;i<n;i++){
        if(a[i]==k){
            count++;
        }
    }
    printf("%d",count);
return 0;
}
