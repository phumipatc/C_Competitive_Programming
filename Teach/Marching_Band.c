/*
	Task :
	Author : Phumipat C.
	Lang : C
	School : RYW
*/
#include<stdio.h>
int main(){
    int q,w,l;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&w,&l);
        printf("%d %d\n",2*(w+l),w*l);
    }
	return 0;
}
