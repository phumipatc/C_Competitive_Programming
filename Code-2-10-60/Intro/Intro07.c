/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C
*/
#include<stdio.h>
int main()
{
    int n,i;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        printf("%d ",i);
    }
    printf("\n");

    i=n;
    while(i>=1){
        printf("%d ",i);
        i--;
    }
    printf("\n");

    i=1;
    do{
        if(i%2==0){
            printf("%d ",i);
            }i++;
        }while(i<=n);
    printf("\n");

    for(i=n;i>=2;i+=0){
            if(i%2==0){
                for(i=n;i>=2;i-=2){
                    printf("%d ",i);
                }
            }else if(i%2==1){
                for(i=n-1;i>=2;i-=2){
                    printf("%d ",i);
                }
            }
        }
        printf("\n");

        i=1;
        while(i<=n){
            if(n%2==1){
                for(i=1;i<=n;i+=2){
                    printf("%d ",i);
                }
            }else if(n%2==0){
                for(i=1;i<=n-1;i+=2){
                    printf("%d ",i);
                }
            }
        }
        printf("\n");

        i=n;
        do{
            if(i%2==1)
                    printf("%d ",i);
                i--;
        }while(i>=1);
return 0;
}
