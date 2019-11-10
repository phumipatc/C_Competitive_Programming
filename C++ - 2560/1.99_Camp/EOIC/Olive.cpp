/*
    TASK :
    AUTHOR : Boss
    SCHOOL : RYW
    LANG : C++
*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 1000002

int a[100005],b[MAX],c[MAX];

int main(void) {
	int i,n,j;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		b[a[i]]++;
	}
	for(i=1;i<MAX;i++){
		if(b[i]){
			for(j=i;j<MAX;j+=i)
				c[j]+=b[i];
		}
	}
	for(i=0;i<n;i++){
		printf("%d\n",c[a[i]]-1);
	}
	return 0;
}
