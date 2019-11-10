/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C
*/
#include<stdio.h>
int main()
{
    int q,a,i;
    scanf("%d",&q);
    for(i=0;i<q;i++){
        scanf("%d",&a);
    while(a!=0){
        if(a>=1000){
            printf("M");
            a-=1000;
        }else if(a<1000 && a>=500){
            if(a>=900 && a<1000){
                printf("CM");
                a-=900;
            }
            else{
                printf("D");
            a-=500;
            }
        }else if(a<500 && a>=100){
            if(a>=400 && a<500){
                printf("CD");
                a-=400;
            }
            else{
                printf("C");
            a-=100;
            }
        }else if(a<100 && a>=50){
            if(a>=90 && a<100){
                printf("XC");
                a-=90;
            }
            else{
                printf("L");
            a-=50;
            }
        }else if(a<50 && a>=10){
            if(a>=40 && a<50){
                printf("XL");
                a-=40;
            }
            else{
                printf("X");
            a-=10;
            }
        }else if(a<10 && a>=5){
            if(a>=9 && a<10){
                printf("IX");
                a-=9;
            }
            else{
                printf("V");
            a-=5;
            }
        }else{
            if(a>=4 && a<5){
                printf("IV");
                a-=4;
            }
            else{
                printf("I");
            a--;
        }
        }
    }
    }
return 0;
}
