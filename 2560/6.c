#include<stdio.h>
int main(){
    int n,i,j;
    scanf("%d",&n);


    for(i=1;i<=n;i++){
        for(j=i;j!=i+n;j++){
            printf("%d ",j);
        }
        printf("\n");
    }


    for(i=1;i<=n;i++){
        for(j=i;j!=i+n;j++){
            if(j==n)
                printf("%d ",j);
            if(j!=n)
                printf("%d ",j%n);
        }
        printf("\n");
    }
    return 0;
}
