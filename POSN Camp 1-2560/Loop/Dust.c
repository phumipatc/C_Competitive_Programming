/*
	Task :
	Author : Phumipat C.
	Lang : C
	School : RYW
*/
#include<stdio.h>
int main(){
    int n,i,j;
    scanf("%d",&n);
    for(i=1;i<n;i++){
        for(j=i;j<n;j++){
            printf("-");
        }
        for(j=1;j<=i;j++){
            printf("+");
        }
        for(j=2;j<=i;j++){
            printf("+");
        }
        for(j=i;j<n;j++){
            printf("-");
        }
        printf("\n");
    }
    for(i=1;i<n;i++)
        printf("+");
    printf("*");
    for(i=1;i<n;i++)
        printf("+");
    printf("\n");
    for(i=1;i<n;i++){
        for(j=1;j<=i;j++){
            printf("-");
        }
        for(j=i;j<n;j++){
            printf("+");
        }
        for(j=i+1;j<n;j++){
            printf("+");
        }
        for(j=1;j<=i;j++){
            printf("-");
        }
        printf("\n");
    }
	return 0;
}
