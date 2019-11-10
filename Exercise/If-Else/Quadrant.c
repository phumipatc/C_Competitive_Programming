/*
    TASK:
    AUTHOR:
    SCHOOL:RYW
    LANG: C
*/
#include<stdio.h>
int main()
{
    int a;
    scanf("%d",&a);
    if(((a%360)<90&&(a%360)>0)||((a%360)<-270&&(a%360)>-360)){
        printf("1");
    }else if(((a%360)<180&&(a%360)>90)||((a%360)<-180&&(a%360)>-270)){
        printf("2");
    }else if(((a%360)<270&&(a%360)>180)||((a%360)<-90&&(a%360)>-180)){
        printf("3");
    }else if(((a%360)<360&&(a%360)>270)||((a%360)<0&&(a%360)>-90)){
        printf("4");
    }else if((a%360)==0||(a%360)==180||(a%360)==-180){
        printf("x-axis");
    }else if((a%360)==90||(a%360)==-90||(a%360)==270||(a%360)==-270){
        printf("y-axis");
    }
return 0;
}
