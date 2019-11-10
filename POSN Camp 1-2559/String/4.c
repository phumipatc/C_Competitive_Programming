/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C
*/
#include<stdio.h>
#include<string.h>
char a[2000];
int main()
{
    int len,i,j,c;
    scanf(" %s %d",a,&c);
    len = strlen(a);
    for(i=0;i<len;i+=c){
        for(j=i+c-1;j>=i;j--){
            if(j<len)
                printf("%c",a[j]);
        }
    }
return 0;
}
