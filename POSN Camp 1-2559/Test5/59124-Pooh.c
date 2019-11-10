#include<stdio.h>
#include<string.h>
char a[50];
int main()
{   int i,n,k,m,len;
    scanf(" %s",a);
    len = strlen(a);
    for(i=1;i<=len;i++){
        if(i%3==0){
            printf("..*.");
        }else if(i%3==1){
            printf("..#.");
        }else{
            printf("..#.");
        }
    }
    printf(".\n");
    for(i=1;i<=len;i++){
        if(i%3==0){
            printf(".*.*");
        }else if(i%3==1){
            printf(".#.#");
        }else{
            printf(".#.#");
        }
    }
    printf(".\n");
    for(i=1;i<=len;i++){
        if(i%3==0){
            printf("*.%c.",a[i-1]);
        }else if(i%3==1){
            if(i>3)
                printf("*");
            else
                printf("#");
            printf(".%c.",a[i-1]);
        }else{
            printf("#.%c.",a[i-1]);
        }
    }
    if(len%3==0){
        printf("*");
    }else{
        printf("#");
    }
    printf("\n");
    for(i=1;i<=len;i++){
        if(i%3==0){
            printf(".*.*");
        }else if(i%3==1){
            printf(".#.#");
        }else{
            printf(".#.#");
        }
    }
    printf(".\n");
    for(i=1;i<=len;i++){
        if(i%3==0){
            printf("..*.");
        }else if(i%3==1){
            printf("..#.");
        }else{
            printf("..#.");
        }
    }
    printf(".\n");
    return 0;
}
