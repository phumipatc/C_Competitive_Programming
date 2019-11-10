#include<stdio.h>
int main()
{
    int start,end,i,k,n,ch1,ch2,ch3,ch4,ch5,ch6,ch7,ch8,ch9,ch0;
    ch1=ch2=ch3=ch4=ch5=ch6=ch7=ch8=ch9=ch0=0;
    scanf("%d %d",&start,&end);
    for(i=start;i<=end;i++){
        n=i;
        while(n>0){
            k=n%10;
            switch(k){
                case 0: ch0++; break;
                case 1: ch1++; break;
                case 2: ch2++; break;
                case 3: ch3++; break;
                case 4: ch4++; break;
                case 5: ch5++; break;
                case 6: ch6++; break;
                case 7: ch7++; break;
                case 8: ch8++; break;
                case 9: ch9++; break;
        }
        n=n/10;
    }
    }
    printf("%d %d %d %d %d %d %d %d %d %d",ch0,ch1,ch2,ch3,ch4,ch5,ch6,ch7,ch8,ch9);
    return 0;
}
