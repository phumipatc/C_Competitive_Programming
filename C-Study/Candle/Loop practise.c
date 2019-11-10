#include<stdio.h>
int main()
{
    int n,i;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        printf("%d ",i);
    }
    printf("\n");
    for(i=n-(n%2);i>0;i-=2){
        printf("%d ",i);
    }
    return 0;
}
