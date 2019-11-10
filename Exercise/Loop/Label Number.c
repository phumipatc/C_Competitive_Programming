/*
    TASK:
    AUTHOR:
    SCHOOL:RYW
    LANG: C
*/
#include<stdio.h>
#include<math.h>
int main()
{
   int a,b,x0,x1,x2,x3,x4,x5,x6,x7,x8,x9,n,k,m;

    scanf("%d %d",&a,&b);
    x0=0;x1=0;x2=0;x3=0;x4=0;x5=0;x6=0;x7=0;x8=0;x9=0;
    for(m=a;m<=b;m++){
        n=m;
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
