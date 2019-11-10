#include<stdio.h>
#include<ctype.h>
int main(){
    char a;
    scanf("%c",&a);
    if(a<=88&&a>=65){
        printf("%c",a+2);
    }else if(a>=97&&a<=120){
        printf("%c",a+2);
    }else if(a>120){
        printf("%c",a-24);
    }else{
        printf("%c",a-24);
    }
    return 0;
}

