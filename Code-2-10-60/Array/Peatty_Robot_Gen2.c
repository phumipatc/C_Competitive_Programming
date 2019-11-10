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
    int len,i,now=1;
    scanf(" %s",a);
    len=strlen(a);
    for(i=0;i<len;i++){
        if(a[i]=='N'){
            if(now==1){
                printf("F");
            }else if(now==2){
                printf("RRRF");
                now=1;
            }else if(now==3){
                printf("RRF");
                now=1;
            }else if(now==4){
                printf("RF");
                now=1;
            }
        }else if(a[i]=='S'){
            if(now==1){
                printf("RRF");
                now=3;
            }else if(now==2){
                printf("RF");
                now=3;
            }else if(now==3){
                printf("F");
            }else if(now==4){
                printf("RRRF");
                now=3;
            }
        }else if(a[i]=='W'){
            if(now==1){
                printf("RRRF");
                now=4;
            }else if(now==2){
                printf("RRF");
                now=4;
            }else if(now==3){
                printf("RF");
                now=4;
            }else if(now==4){
                printf("F");
            }
        }else if(a[i]=='E'){
            if(now==1){
                printf("RF");
                now=2;
            }else if(now==2){
                printf("F");
            }else if(now==3){
                printf("RRRF");
                now=2;
            }else if(now==4){
                printf("RRF");
                now=2;
            }
        }else{
            printf("Z");
            now=1;
        }
    }
    return 0;
}
