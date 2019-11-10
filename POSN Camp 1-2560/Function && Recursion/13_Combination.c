/*
TASK: Combination
LANG: C
AUTHOR: PeaTT~
*/
#include <stdio.h>
#include <stdlib.h>

int n,r,k,count;
int a[20],b[20];

void combine(int state,int p){
	int i;
	if(state==r){
		count++;
		if(count==k){
			for(i=0;i<r-1;i++)
				printf("%d ",b[i]);
			printf("%d\n",b[i]);
			exit(0);
		}
	}
	else{
		for(i=p;i<n;i++){
			if(a[i]!=-1){
				a[i]=-1;
				b[state]=i+1;
				combine(state+1,i);
				a[i]=0;
			}
		}
	}
}

int main(){
	scanf("%d %d %d",&n,&r,&k);
	count=0;
	combine(0,0);
    return 0;
}
