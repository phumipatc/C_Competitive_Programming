/*
	Task :
	Author : Phumipat C.
	Lang : C
	School : RYW
*/
#include<stdio.h>
int main(){
    int q,n,i,sq,countt;
    scanf("%d",&q);
    while(q--){
        countt = 0;
        scanf("%d",&n);
        sq = sqrt(n);
        for(i=2;i<=sq;i++){
            if(n%i == 0){
                countt++;
                while(n%i == 0) n/=i;
            }
        }
        if(n!=1)    countt++;
        printf("%d\n",countt);
    }
	return 0;
}
