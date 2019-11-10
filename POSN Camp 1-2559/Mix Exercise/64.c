/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char now,a[100];
int main()
{
    int len,i;
    scanf(" %s",a);
    len = strlen(a);
    now='n';
    for(i=0;i<len;i++){
        if(a[i]=='N'){
            if(now=='n'){
                printf("F");
            }else if(now=='e'){
                printf("RRRF");
            }else if(now=='s'){
                printf("RRF");
            }else if(now=='w'){
                printf("RF");
            }
            now='n';
        }else if(a[i]=='E'){
            if(now=='n'){
                printf("RF");
            }else if(now=='e'){
                printf("F");
            }else if(now=='s'){
                printf("RRRF");
            }else if(now=='w'){
                printf("RRF");
            }
            now='e';
        }else if(a[i]=='S'){
            if(now=='n'){
                printf("RRF");
            }else if(now=='e'){
                printf("RF");
            }else if(now=='s'){
                printf("F");
            }else if(now=='w'){
                printf("RRRF");
            }
            now='s';
        }else if(a[i]=='W'){
            if(now=='n'){
                printf("RRRF");
            }else if(now=='e'){
                printf("RRF");
            }else if(now=='s'){
                printf("RF");
            }else if(now=='w'){
                printf("F");
            }
            now='w';
        }else if(a[i]=='Z'){
            printf("Z");
            now='n';
        }
    }
return 0;
}
