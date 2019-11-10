/*
    TASK :
    AUTHOR : Boss
    SCHOOL : RYW
    LANG : C
*/
#include<stdio.h>
int main()
{
    int a,b,now;
    scanf("%d",&a);
    a=a%360;
    if(a==0 || (a>=1 && a<=15)){
        printf("6");
    }else if((a>15 && a<=30) || (a>30 && a<=45)){
        printf("7");
    }else if((a>45 && a<=60) || (a>60 && a<=75)){
        printf("8");
    }else if((a>75 && a<=90) || (a>90 && a<=105)){
        printf("9");
    }else if((a>105 && a<=120) || (a>120 && a<=135)){
        printf("10");
    }else if((a>135 && a<=150) || (a>150 && a<=165)){
        printf("11");
    }else if((a>165 && a<=180) || (a>180 && a<195)){
        printf("12");
    }else if((a>=195 && a<=210) || (a>210 && a<=225)){
        printf("1");
    }else if((a>225 && a<=240) || (a>240 && a<=255)){
        printf("2");
    }else if((a>255 && a<=270) || (a>270 && a<=285)){
        printf("3");
    }else if((a>285 && a<=300) || (a>300 && a<=315)){
        printf("4");
    }else if((a>315 && a<=330) || (a>330 && a<=345)){
        printf("5");
    }else if(a>345 && a<360){
        printf("6");
    }
    return 0;
}
