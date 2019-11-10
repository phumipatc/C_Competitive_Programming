#include<stdio.h>
#include<ctype.h>
int main(){
    char x;
    scanf("%c",&x);
    if(islower(x)){
    printf("Small");
    }else if(isupper(x)){
        printf("Big");
    }else{
        printf("Not Alphabet");
    }
    return 0;
}

