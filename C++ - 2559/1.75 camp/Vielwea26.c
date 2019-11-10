/*
TASK: Viel wear
LANG: C
AUTHOR: PeaTT~
*/
#include <stdio.h>
int main(){
    int n,i,a,sum=0; //number can build between 1 to sum
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a);
        if(a>1){
			printf("%d\n",sum+1); return 0;
		}
        else sum+=a;
    }
    printf("%d\n",sum+1);
	return 0;
}
