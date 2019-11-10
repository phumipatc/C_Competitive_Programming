#include<stdio.h>
int main(){
    char a;
    scanf(" %c",&a);
    if(a!=122)
        printf("%c\n",a+1);
    else
        printf("a");
    return 0;
}
