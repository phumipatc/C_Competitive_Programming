/*
	Task :
	Author : Phumipat C.
	Lang : C
	School : RYW
*/
#include<stdio.h>
int main(){
    int a,b;
    scanf("%d %d",&a,&b);
    if(a>b)
        printf("%d Larger\n",a);
    else if(b>a)
        printf("%d Larger\n",b);
    else
        printf("%d Equal %d\n",a,b);
	return 0;
}
