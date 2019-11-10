#include<stdio.h>
int a[1200];
int main(){
    int n,k,i,countt=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    scanf("%d",&k);
    for(i=0;i<n;i++)
        if(a[i]==k)
            countt++;
    for(i=n-1;i>=0;i--)
        printf("%d ",a[i]);
    printf("\n%d",countt);
    return 0;
}
