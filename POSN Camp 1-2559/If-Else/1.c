/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C
*/
#include<stdio.h>
int main()
{
    int x;
    scanf("%d",&x);
    if(x>=80 && x<=100){
        printf("A");
    }else if(x>=75){
        printf("B+");
    }else if(x>=70){
        printf("B");
    }else if(x>=65){
        printf("C+");
    }else if(x>=60){
        printf("C");
    }else if(x>=55){
        printf("D+");
    }else if(x>=50){
        printf("D");
    }else if(x<50){
        printf("F");
    }
return 0;
}
