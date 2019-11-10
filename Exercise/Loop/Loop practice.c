/*
    TASK:
    AUTHOR:
    SCHOOL:RYW
    LANG: C
*/
#include<stdio.h>
int main()
{
    int n,x;
    scanf("%d",&n);
    for(x=1;x<=n;x++){
        printf("%d ",x);
    }
        printf("\n");
        x=n;
    while(x>=1){
        printf("%d ",x);
        x--;
    }printf("\n");

    x=1;
    do{
        if(x%2==0)
            printf("%d ",x);
            x++;
        }while(x<=n);
            printf("\n");

        for(x=n;x>=2;x+=0){
            if(x%2==0){
                for(x=n;x>=2;x-=2){
                    printf("%d ",x);
                }
            }else if(x%2==1){
                for(x=n-1;x>=2;x-=2){
                    printf("%d ",x);
                }
            }
        }
        printf("\n");

        x=1;
        while(x<=n){
            if(n%2==1){
                for(x=1;x<=n;x+=2){
                    printf("%d ",x);
                }
            }else if(n%2==0){
                for(x=1;x<=n-1;x+=2){
                    printf("%d ",x);
                }
            }
        }
        printf("\n");

        x=n;
        do{
            if(x%2==1)
                    printf("%d ",x);
                x--;
        }while(x>=1);
return 0;
}
