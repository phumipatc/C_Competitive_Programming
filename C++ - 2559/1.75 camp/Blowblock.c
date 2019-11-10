/*
TASK: Blowblock
LANG: C
AUTHOR: PeaTT~
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int b[63000],size;
}arr;
arr a[4];

int sort(const void* a,const void* b){
	return *(int *)a - *(int *)b;
}

int main(){
	int n,i,j,sum=0,at;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			at= (i%2)*2 + (j%2);
			scanf("%d",&a[at].b[a[at].size++]);
		}
	}
	for(i=0;i<4;i++)
		qsort(a[i].b,a[i].size,sizeof(a[i].b[0]),sort);
	for(i=0;i<n*n/4;i++){
		sum+=(a[0].b[i]*a[1].b[i]*a[2].b[i]*a[3].b[i]);
	}
	printf("%d\n",sum);
	return 0;
}
