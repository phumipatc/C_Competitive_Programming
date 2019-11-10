#include<stdio.h>
#include<ctype.h>
int main(){
    char a;
    scanf("%c",&a);
    if(isupper(a)){
    printf("%c",tolower(a));
}else if(islower(a)){
    printf("%c",toupper(a));
}
    return 0;
}

