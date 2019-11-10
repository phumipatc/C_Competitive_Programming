/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C
*/
#include<stdio.h>
#include<string.h>
#include<ctype.h>
char a[1000];
int main(){
    int len,i,sum=0,now=0;
    scanf(" %s",a);
    len=strlen(a);
    for(i=0;i<len;i++,now++){
        if(isupper(a[i])){
            if(now%4==1)
                sum+=3,now+=3;
            else if(now%4==2)
                sum+=2,now+=2;
            else if(now%4==3)
                sum++,now++;
        }
    }
    printf("%d\n",sum);
return 0;
}
