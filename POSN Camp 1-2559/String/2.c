/*
    TASK:FSM
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C
*/
#include<stdio.h>
#include<string.h>
char a[110];
int main()
{
    int n,len,i;
    scanf("%s",a);
    len=strlen(a);
    printf("%d ",len);
    if(len==1 || len==0){
        printf("Reject");
        return 0;
    }
    for(i=0;i<len;i++){
            if(a[i]==a[i+1]){
                printf("Reject");
                return 0;
            }else if(a[i]!=a[i+1]){
                n=1;
            }
            }
    if(n==1){
        printf("Accept");
    }
return 0;
}
