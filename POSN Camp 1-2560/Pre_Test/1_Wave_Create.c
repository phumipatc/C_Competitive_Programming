/*
    TASK :
    AUTHOR : Boss
    SCHOOL : RYW
    LANG :
*/
#include<stdio.h>
int main()
{
    int n,i,j,q;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        if(n==1){
            printf("#\n");
        }else{
            for(j=0; j<(n-1)*4+1; j++)
                printf("#");
            printf("\n");
            for(j=0; j<(n-1)*4+1; j++){
                if(j==(n-1)*4)  printf("#");
                else            printf(".");
            }
            printf("\n");
            for(i=1; i<=n*2-3; i++){
                for(j=0; j<i; j++){
                    if(j%2==0)  printf("#");
                    else        printf(".");
                }
                for(j=0; j<=(n*2-3)-i; j++){
                    if(i%2==1)  printf("##");
                    else        printf("..");
                }
                for(j=0; j<i+1; j++){
                    if((j%2==1&&i%2==1)||(i%2==0&&j%2==0))  printf("#");
                    else                                    printf(".");
                }
                printf("\n");
            }
            for(i=0; i<n*2-2; i++){
                for(j=0; j<(n*2-2)-i; j++){
                    if(j%2==0)  printf("#");
                    else        printf(".");
                }
                for(j=-1; j<i; j++){
                    if(i%2==0)  printf("..");
                    else        printf("##");
                }
                for(j=0; j<n*2-2-i-1; j++){
                    if((j%2==1&&i%2==1)||(i%2==0&&j%2==0))  printf("#");
                    else                                    printf(".");
                }
                printf("\n");
            }
        }
    }
    return 0;
}
