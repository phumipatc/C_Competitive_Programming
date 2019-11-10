/*
    Task :
    Author : Boss
    School : RYW
    Language : C
*/
#include<stdio.h>
char a[5000];
int main()
{
    int i,q,len,value;
    scanf("%d",&q);
    while(q--){
        scanf(" %s",a);
        len=strlen(a);
        value=0;
        for(i=0;i<len;i++){
            if(a[i]=='C' && a[i+1]=='M'){
                value+=900;
                i++;
            }else if(a[i]=='C' && a[i+1]=='D'){
                value+=400;
                i++;
            }else if(a[i]=='X' && a[i+1]=='C'){
                value+=90;
                i++;
            }else if(a[i]=='X' && a[i+1]=='L'){
                value+=40;
                i++;
            }else if(a[i]=='I' && a[i+1]=='X'){
                value+=9;
                i++;
            }else if(a[i]=='I' && a[i+1]=='V'){
                value+=4;
                i++;
            }else if(a[i]=='M'){
                value+=1000;
            }else if(a[i]=='D'){
                value+=500;
            }else if(a[i]=='C'){
                value+=100;
            }else if(a[i]=='L'){
                value+=50;
            }else if(a[i]=='X'){
                value+=10;
            }else if(a[i]=='V'){
                value+=5;
            }else if(a[i]=='I'){
                value+=1;
            }
        }
        printf("%d\n",value);
    }
    return 0;
}
