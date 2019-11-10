#include<stdio.h>
int main()
{
    int x,y,i;
    scanf("%d %d",&x,&y);
    for(i=y;i>=x;i--){
        if(i%400==0 || (i%4==0 && i%100!=0))
            printf("%d\n",i);
    }
    return 0;
}
