#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    if(n>=80)
        printf("A\n");
    else if(n>=75)
        printf("B+\n");
    else if(n>=70)
        printf("B\n");
    else if(n>=65)
        printf("C+\n");
    else if(n>=60)
        printf("C\n");
    else if(n>=55)
        printf("D+\n");
    else if(n>=50)
        printf("D\n");
    else
        printf("F\n");
    return 0;
}
