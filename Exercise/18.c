#include<stdio.h>
int main(){
    int a,b,c,d;
    scanf("%d %d",&c,&d);
    for(a=1;a<=c;a++){
        for(b=1;b<=d;b++){
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
