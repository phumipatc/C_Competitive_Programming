/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
long long a[100];
long long count,min;
int main()
{
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%lld",&a[i]);
    }
    for(i=0;i<n-1;i++){
        if(a[i]>a[i+1]){
            min=a[i+1];
        }else if(a[i+1]>a[i]){
            min=a[i];
        }
    }
    for(i=1;i<min;i++)
        if(a[i]%i==0 && a[i+1]%i==0)
        count++;
    printf("%lld",count);
return 0;
}
