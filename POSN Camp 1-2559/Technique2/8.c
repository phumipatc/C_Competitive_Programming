/*
    TASK: Divide
    AUTHOR: Phumipat
    SCHOOL: RYW
    LANG: C
            */
#include<stdio.h>
#include<string.h>
#include<ctype.h>
int check7(char a[],int len){
    char b[100];
    int i,temp,sum=0,plus=1;
    memset(b,'0',sizeof b);
    if(len%3==0)    strcpy(b,a);
    else if(len%3==1)   strcpy(&b[2],a);
    else if(len%3==2)   strcpy(&b[1],a);
    len=strlen(b);
    for(i=len-3;i>=0;i-=3){
        temp=(b[i]-'0')*100+(b[i+1]-'0')*10+b[i+2]-'0';
            if(plus)    sum+=temp,plus=0;
            else    sum-=temp,plus=1;
        }
        if(sum%7==0){
            printf("7 * %d\n",sum/7);
            return 1;
        }
    return 0;
}
int check11(char a[],int len){
    char b[100];
    int i,temp,sum=0,plus=1;
    len=strlen(b);
    for(i=len-1;i>=0;i--){
            temp=(b[i]-'0');

            if(plus)    sum+=temp,plus=0;
            else    sum-=temp,plus=1;
        }
        if(sum%11==0){
            printf("11 * %d\n",sum/11);
            return 1;
        }
    return 0;
}
int check99(char a[],int len){
    char b[100];
    int i,temp,sum=0;
    memset(b,'0',sizeof b);
    if(len%2==0)    strcpy(b,a);
    else if(len%2==1)   strcpy(&b[1],a);
    len=strlen(b);
    for(i=len-2;i>=0;i-=2){
        temp=(b[i]-'0')*10+(b[i+1]-'0');
               sum+=temp;
        }
        if(sum%99==0){
            printf("99 * %d\n",sum/99);
            return 1;
        }
    return 0;
}

int main()
{
    char a[100];
    int len;
    scanf(" %s",a);
    len=strlen(a);

    int ch1,ch2,ch3;
    ch1=check7(a,len);
    ch2=check11(a,len);
    ch3=check99(a,len);
    if(ch1==0&&ch2==0&&ch3==0)
        printf("%s",a);

       return 0;
}
