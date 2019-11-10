/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int mic[200]={1};
int main()
{
    int n,i;
    scanf("%d",&n);
    if(n<6){
        printf("no");
        return 0;
    }
    for(i=6;i<=n;i++){
        if(i-6>=0 && mic[i-6]==1)   mic[i]=1;
        if(i-9>=0 && mic[i-9]==1)   mic[i]=1;
        if(i-20>=0 && mic[i-20]==1)   mic[i]=1;
    }
    for(i=6;i<=n;i++){
        if(mic[i])
            printf("%d\n",i);
    }
return 0;
}
