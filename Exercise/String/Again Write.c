/*
    TASK:
    AUTHOR:
    SCHOOL:RYW
    LANG: C
*/
#include<stdio.h>
#include<string.h>
char a[100];
char k[100];
int main()
{
    int i,j,x,lena,lenb;
    scanf("%d",&x);
    for(j=0;j<x;j++){
        scanf(" %s",a);
        char b[42000];
        scanf(" %s",b);
        lena=strlen(a);
        lenb=strlen(b);
        for(i=0;i<lenb;i++){
            k[j]=strcmp(a[i],b[i]);

        }

        for(j=1;j<=x;j++){
            if(k[j]==0){
                printf("Yes\n");
            }else{
                printf("No\n");
            }
        }
return 0;
}
