#include<stdio.h>
int main(){
    int n,i;
    scanf("%d",&n);

    //Loop For
    for(i=1;i<=n;i++)
        printf("%d ",i);
    printf("\n");

    //Loop While
    i=n;
    while(i!=0){
        printf("%d ",i);
        i--;
    }
    printf("\n");

    //Loop For
    for(i=1;i<=n;i++)
        if(i%2==0)
            printf("%d ",i);
    printf("\n");

    //Loop For
    for(i=n;i>1;i--)
        if(i%2==0)
            printf("%d ",i);
    printf("\n");

    //Loop While
    i=1;
    while(i!=n){
        if(i%2==1)
            printf("%d ",i);
        i++;
    }
    printf("\n");

    //Loop While
    i=n;
    while(i!=0){
        if(i%2==1)
            printf("%d ",i);
        i--;
    }
    printf("\n");
    return 0;
}
