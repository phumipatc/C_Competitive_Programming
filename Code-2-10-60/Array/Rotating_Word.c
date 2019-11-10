/*
    Task :
    Author : Boss
    School : RYW
    Language : C
*/
#include<stdio.h>
#include<string.h>
char a[2000];
int main()
{
    int k,len,i;
    scanf(" %s %d",a,&k);
    len=strlen(a);
    for(i=len-k;i<len;i++)
        printf("%c",a[i]);
    for(i=0;i<len-k;i++)
        printf("%c",a[i]);
return 0;
}
