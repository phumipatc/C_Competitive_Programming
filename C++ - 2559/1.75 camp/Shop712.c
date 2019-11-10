/*
TASK: Shop 7_12
LANG: C
AUTHOR: PeaTT~
*/
#include <stdio.h>
int c[20000];
int main(){
	int a,b,n,i,k;
	scanf("%d %d %d",&a,&b,&n);
	c[0]=1;
	if(a>b)
		i=a,a=b,b=i;
	for(i=1;i<=10100;i++){
		if(i-a>=0 && c[i-a]==1)		c[i]=1;
		if(i-b>=0 && c[i-b]==1)		c[i]=1;
	}
	k=-1;
	for(i=10100;i>=1;i--){
		if(c[i]) k=i;
		c[i]=k;
	}
	while(n--){
		scanf("%d",&i);
		printf("%d\n",c[i]);
	}
	return 0;
}
