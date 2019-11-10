/*
    TASK:Tree Curt
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<stdio.h>
int a[10000];
int main()
{
    int i,n,start;
    scanf("%d",&n);
    start=n/2+1;
    for(i=start;i<=n;i++)
        scanf("%d",&a[i]);
    for(i=start-1;i>=1;i--){
        if(a[2*i]<a[2*i+1]){
            a[i]=a[2*i];
            a[2*i+1]-=a[2*i];
            a[2*i]=0;
        }else{
            a[i]=a[2*i+1];
            a[2*i]-=a[2*i+1];
            a[2*i+1]=0;
        }
    }
    int sum;
    for(sum=0,i=1;i<=n;i++){
        sum+=a[i];
    }
    printf("%d",sum);
return 0;
}
