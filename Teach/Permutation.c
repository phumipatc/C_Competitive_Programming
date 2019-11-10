/*
	Task :
	Author : Phumipat C.
	Lang : C
	School : RYW
*/
#include<stdio.h>
int use[55],mark[55],n;
void permute(int state){
    if(state == n){
        for(int i=0;i<n;i++)
            printf("%d ",use[i]);
        printf("\n");
        return ;
    }
    for(int i=1;i<=n;i++){
        if(!mark[i]){
            mark[i] = 1;
            use[state] = i;
            permute(state+1);
            mark[i] = 0;
        }
    }
}
int main(){
    scanf("%d",&n);
    permute(0);
	return 0;
}
