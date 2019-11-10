/*
    Task :
    Author : Boss
    School : RYW
    Language : C
*/
#include<stdio.h>
int main()
{
    int i,n,a,b,sum=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&a);
        if(i!=1){
            if(a>=80 || (a>=20 && a-b>=10))   sum++;
        }
        b=a;
    }
    printf("%d",sum);
    return 0;
}
