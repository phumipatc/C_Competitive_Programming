/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C
*/
#include<stdio.h>
int main(){
    int n,i;
    int I=0,V=0,X=0,L=0,C=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        if(i>=300){
            C+=3;
        }
        else if(i>=200){
            C+=2;
        }
        else if(i>=100){
            C+=1;
        }
        int h = i%100;
        if(h>=90){
            X++;
            C++;
        }
        else if(h>=80){
            L++;
            X+=3;
        }
        else if(h>=70){
            L++;
            X+=2;
        }
        else if(h>=60){
            L++;
            X++;
        }
        else if(h>=50){
            L++;
        }
        else if(h>=40){
            X++;
            L++;
        }
        else if(h>=30){
            X+=3;
        }
        else if(h>=20){
            X+=2;
        }
        else if(h>=10){
            X++;
        }
        int l = h%10;
        if(l>=9){
            I++;
            X++;
        }
        else if(l>=8){
            V++;
            I+=3;
        }
        else if(l>=7){
            V++;
            I+=2;
        }
        else if(l>=6){
            V++;
            I++;
        }
        else if(l>=5){
            V++;
        }
        else if(l>=4){
            I++;
            V++;
        }
        else if(l>=3){
            I+=3;
        }
        else if(l>=2){
            I+=2;
        }
        else if(l>=1){
            I++;
        }
    }
    printf("%d %d %d %d %d",I,V,X,L,C);
}
