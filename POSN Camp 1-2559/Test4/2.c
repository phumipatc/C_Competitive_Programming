/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    int i,j,n,p,q,a,b,c,count=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d %d %d %d %d",&p,&q,&a,&b,&c);
        for(p;p<=q;p++){
            if(p%a!=0 && p%b!=0 && p%c!=0){
                count++;
            }
        }
        printf("%d\n",count);
        count=0;
    }
return 0;
}
