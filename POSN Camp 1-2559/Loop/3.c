/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C
*/
#include<stdio.h>
int main()
{
    int n,k,i,x,y,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10;
    scanf("%d %d",&x,&y);
    a0=0,a1=0,a2=0,a3=0,a4=0,a5=0,a6=0,a7=0,a8=0,a9=0,a10=0;
    for(i=x;i<=y;i++){
        n=i;
        while(n>0){
            k=n%10;
            switch(k){
            case 0: a0++; break;
            case 1: a1++; break;
            case 2: a2++; break;
            case 3: a3++; break;
            case 4: a4++; break;
            case 5: a5++; break;
            case 6: a6++; break;
            case 7: a7++; break;
            case 8: a8++; break;
            case 9: a9++; break;
        }
        n=n/10;
    }
    }
    printf("%d %d %d %d %d %d %d %d %d %d",a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10);
return 0;
}
