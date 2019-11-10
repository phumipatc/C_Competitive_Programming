/*
    TASK :
    AUTHOR : Boss
    SCHOOL : RYW
    LANG : C
*/
#include<stdio.h>
#include<string.h>
char a[1200];
int main()
{
    int n,k,len,i;
    scanf(" %s %d",a,&k);
    len=strlen(a);
    for(i=len-k;i<len;i++)
        printf("%c",a[i]);
    for(i=0;i<len-k;i++)
        printf("%c",a[i]);
    return 0;
}
