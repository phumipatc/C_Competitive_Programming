/*
	Task :
	Author : Phumipat C.
	Lang : C
	School : RYW
*/
#include<stdio.h>
int main(){
    int i = 1,sum = 0;
    do{
        sum+=i;
        i+=2;
    }while(i<=100);
    printf("%d\n",sum);
	return 0;
}

