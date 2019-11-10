#include<stdio.h>
int main()
{
    int n,a=6;
    scanf("%d",&n);
    n=n%360;
    while(n>=30){
        a=(a+1)%12;
        n=n-30;
    }
    if(n>15)
        printf("%d",a+1);
    else if(n< 15)
        printf("%d",a);
    else
        printf("%d",a);
    return 0;
}
