/*
    TASK:
    AUTHOR: Phumipat
    SCHOOL: RYW
    LANG: C
            */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char a[100000];
int main()
{
    int n,i,j,len,count=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf(" %s",a);
        len=strlen(a);
        for(j=0;j<len;j++){
        if(a[0]==a[j]){
            count++;
        }
        }
    printf("%d",count);
    count=0;
    }
    return 0;
}

