/*
    Task :
    Author : Boss
    School : RYW
    Language : C
*/
#include<stdio.h>;
int main()
{
    int a,b,i,k,n,x1,x2,x3,x4,x5,x6,x7,x8,x9,x0;
    scanf("%d %d",&a,&b);
    x0=x1=x2=x3=x4=x5=x6=x7=x8=x9=0;
    for(i=a;i<=b;i++){
        n=i;
        while(n>0){
            k=n%10;
            switch(k){
                case 0: x0++; break;
                case 1: x1++; break;
                case 2: x2++; break;
                case 3: x3++; break;
                case 4: x4++; break;
                case 5: x5++; break;
                case 6: x6++; break;
                case 7: x7++; break;
                case 8: x8++; break;
                case 9: x9++; break;
        }
        n=n/10;
    }
    }
    printf("%d %d %d %d %d %d %d %d %d %d",x0,x1,x2,x3,x4,x5,x6,x7,x8,x9);
    return 0;
}
