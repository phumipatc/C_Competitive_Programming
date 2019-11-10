/*
    TASK :
    AUTHOR : Boss
    SCHOOL : RYW
    LANG : C
*/
#include<stdio.h>
#include<string.h>
char a[6000],b[6000],c[6000],sum[6000];
int main()
{
    int lena,lenb,i,j,n,m,ch1=0,ch2=0;
    scanf(" %s %s",a,b);
    if(a[0]=='-')
    {
        ch1=1;
        for(i=1; i<lena; i++)
            c[i-1]=a[i];
        strcpy(a,c);
    }
    if(b[0]=='-')
    {
        ch2=1;
        for(i=1; i<lenb; i++)
            c[i-1]=b[i];
        strcpy(b,c);
    }
    n=lena=strlen(a);
    m=lenb=strlen(b);
    m++;
    for(i=0;i<=m;i++){
        if((ch1==ch2){

        }else if(ch1!=ch2){

        }
    }
    return 0;
}
