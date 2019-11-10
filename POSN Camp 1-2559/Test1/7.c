/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C
*/
#include<stdio.h>
int a[20][20];
int main()
{
    int b,c,i,j,x,y,sum=0,n;
    scanf("%d",&n);
    for(j=0;j<n;j++){
        scanf("%d %d",&x,&y);
        if(x*x+y*y<=4)
            sum+=5;
        else if(x*x+y*y<=16)
            sum+=4;
        else if(x*x+y*y<=36)
            sum+=3;
        else if(x*x+y*y<=64)
            sum+=2;
        else if(x*x+y*y<=100)
            sum+=1;




    }
    printf("%d",sum);


       return 0;
}

