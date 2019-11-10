/*
    Task :
    Author : Boss
    School : RYW
    Language : C
*/
#include<stdio.h>
int main()
{
    int q,n;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        if(n>=1000){
            if(n>=1000 && n<2000){
                printf("M");
                n-=1000;
            }else if(n>=2000 && n<3000){
                printf("MM");
                n-=2000;
            }else if(n>=3000 && n<4000){
                printf("MMM");
                n-=3000;
            }
        }
        if(n>=100){
            if(n>=100 && n<200){
                printf("C");
                n-=100;
            }else if(n>=200 && n<300){
                printf("CC");
                n-=200;
            }else if(n>=300 && n<400){
                printf("CCC");
                n-=300;
            }else if(n>=400 && n<500){
                printf("CD");
                n-=400;
            }else if(n>=500 && n<600){
                printf("D");
                n-=500;
            }else if(n>=600 && n<700){
                printf("DC");
                n-=600;
            }else if(n>=700 && n<800){
                printf("DCC");
                n-=700;
            }else if(n>=800 && n<900){
                printf("DCCC");
                n-=800;
            }else if(n>=900 && n<1000){
                printf("CM");
                n-=900;
            }
        }
        if(n>=10){
            if(n>=10 && n<20){
                printf("X");
                n-=10;
            }else if(n>=20 && n<30){
                printf("XX");
                n-=20;
            }else if(n>=30 && n<40){
                printf("XXX");
                n-=30;
            }else if(n>=40 && n<50){
                printf("XL");
                n-=40;
            }else if(n>=50 && n<60){
                printf("L");
                n-=50;
            }else if(n>=60 && n<70){
                printf("LX");
                n-=60;
            }else if(n>=70 && n<80){
                printf("LXX");
                n-=70;
            }else if(n>=80 && n<90){
                printf("LXXX");
                n-=80;
            }else if(n>=90 && n<100){
                printf("XC");
                n-=90;
            }
        }
        if(n>=1){
            if(n==1){
                printf("I\n");
                n-=1;
            }else if(n==2){
                printf("II\n");
                n-=2;
            }else if(n==3){
                printf("III\n");
                n-=3;
            }else if(n==4){
                printf("IV\n");
                n-=4;
            }else if(n==5){
                printf("V\n");
                n-=5;
            }else if(n==6){
                printf("VI\n");
                n-=6;
            }else if(n==7){
                printf("VII\n");
                n-=7;
            }else if(n==8){
                printf("VIII\n");
                n-=8;
            }else if(n==9){
                printf("IX\n");
                n-=9;
            }
        }
    }
    return 0;
}
