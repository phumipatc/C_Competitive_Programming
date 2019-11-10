/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C
*/
#include<stdio.h>
int main()
{
    int n,a,b,j,count=0;
    scanf("%d",&n);
    while(n>=10){
        b=n%10;
        n=n/10;
        for(j=0;j<n;j++){
        if(b==0){
            count++;
        }else{
            break;
        }
        }
    }
    while(n>10){
        n=n/10;
    }
    printf("%d",count/n);
return 0;
}
