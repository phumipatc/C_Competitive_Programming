/*
	Task :
	Author : Phumipat C.
	Lang : C
	School : RYW
*/
#include<stdio.h>
int main(){
    char x;
    scanf("%c",&x);
//    if(isupper(x))
    if(x>='A' && x<='Z')
        printf("Big\n");
//    else if(islower(x))
    else if(x>='a' && x<='z')
        printf("Small\n");
    else
        printf("Not Alphabet\n");
	return 0;
}
