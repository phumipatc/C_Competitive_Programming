/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int a[1000],b[1000];
int cmp(const void* a,const void* b){
    return *(int *)a - *(int *)b;
}
int main()
{
    int n,i;
    long long sum=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(i=0;i<n;i++)
        scanf("%d",&b[i]);
    qsort(a,n,sizeof(a[0]),cmp);
    qsort(b,n,sizeof(b[0]),cmp);
    for(i=0;i<n;i++)
        sum+=((long long)a[i]*b[n-1-i]);
    printf("%lld\n",sum);
return 0;
}
