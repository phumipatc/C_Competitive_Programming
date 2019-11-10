/*
    Task :
    Author : Boss
    School : RYW
    Language : C
*/
#include<stdio.h>
#include<string.h>
char a[120];
int main()
{
    int len,x,y,i;
    scanf(" %s",a);
    len=strlen(a);
    x=y=0;
    for(i=0;i<len;i++){
        if(a[i]=='N'){
            y++;
        }else if(a[i]=='S'){
            y--;
        }else if(a[i]=='W'){
            x--;
        }else if(a[i]=='E'){
            x++;
        }else{
            x=y=0;
        }
    }
    printf("%d %d\n",x,y);
    return 0;
}
