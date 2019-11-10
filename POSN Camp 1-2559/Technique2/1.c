/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C
*/
#include<stdio.h>
#include<string.h>
#include<ctype.h>
char a[100];
char b[100];
char c[100];
int main()
{
    int x,lena,lenb,sum,suma=0,sumb=0,i;
    scanf("%d %s %s",&x,a,b);
    lena=strlen(a);
    lenb=strlen(b);
    for(i=0;i<lena;i++){
        suma*=x;
        if(isalpha(a[i]))
            suma+=(a[i]-'A'+10);
        else
        suma+=(a[i]-'0');
    }
    for(i=0;i<lenb;i++){
        sumb*=x;
        if(isalpha(b[i]))
            sumb+=(b[i]-'A'+10);
        else
        sumb+=(b[i]-'0');
    }
    sum=suma+sumb;
    printf("%d\n",sum);
    i=0;
    while(sum>0){
        if(sum%x<10)
        c[i]=(sum%x)+'0';
        else
            c[i]=(sum%x)-10+'A';
        sum/=x;
        i++;
    }
    int j;
    for(j=i-1;j>=0;j--){
    printf("%c",c[j]);
    }
return 0;
}
