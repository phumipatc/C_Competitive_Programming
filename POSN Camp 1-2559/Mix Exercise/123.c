/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char a[5500],b[5500];
int c[11000];
int main()
{
    int i,j,lena,lenb,m=0,k;
    scanf("%s %s",a,b);
    if(!strcmp(a,"0") || !strcmp(b,"0")){
        printf("0\n");
        return 0;
    }
    if(a[0]=='-'){
        strcpy(a,&a[1]);
        m++;
    }
    if(b[0]=='-'){
        strcpy(b,&b[1]);
        m++;
    }
    if(m==1){
        printf("-");
    }
    lena=strlen(a);
    lenb=strlen(b);
    memset(c,0,sizeof c);
    for(i=lena-1;i>=0;i--){
        for(j=lenb-1,k=lena-1-i;j>=0;j--,k++){
            c[k]+=(a[i]-'0')*(b[j]-'0');
            c[k+1]+=(c[k]/10);
            c[k]%=10;
        }
    }
    for(i=10001;i>=0;i--){
        if(c[i]!=0)
            break;
    }
    for(;i>=0;i--){
        printf("%d",c[i]);
    }
return 0;
}
