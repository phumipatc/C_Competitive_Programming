#include<stdio.h>
#include<string.h>
char a[120],b[125];
int main()
{
    int len,i;
    scanf(" %s",a);
    len=strlen(a);
    if(len%3==1){
        b[0]=b[1]='0';
        strcat(b,a);
        len+=2;
    }else if(len%3==2){
        b[0]='0';
        strcat(b,a);
        len++;
    }else if(len%3==0){
        strcpy(b,a);
    }
    for(i=0;i<len;i+=3){
        if(b[i]-'0'){
            if(b[i+1]-'0'){
                if(b[i+2]-'0'){
                    printf("7");
                }else{
                    printf("6");
                }
            }else{
                if(b[i+2]-'0'){
                    printf("5");
                }else{
                    printf("4");
                }
            }
        }else{
            if(b[i+1]-'0'){
                if(b[i+2]-'0'){
                    printf("3");
                }else{
                    printf("2");
                }
            }else{
                if(b[i+2]-'0'){
                    printf("1");
                }else{
                    printf("0");
                }
            }
        }
    }
    return 0;
}
