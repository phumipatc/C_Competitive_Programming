/*
TASK: Inheritance EOIC#28
LANG: C
AUTHOR: PeaTT~
*/
#include<stdio.h>
int n,j,ans[100001]={0},f=0;
int main()
{
	scanf("%d",&n);
	if(n<0){
		printf("-1\n");		return 0;
	}
	if(n==0){
		printf("10\n");		return 0;
	}
	if(n<10){
		printf("%d\n",n);	return 0;
	}
	j=9;
	while(j>1&&n>1)
	{
		if(n%j==0)
			n = n/j,ans[f]= j,f++;
		else 
			j--;
	}
	if(n!=1){
		printf("-1\n");	return 0;
	}
	for(j=f-1;j>=0;j--)
		printf("%d",ans[j]);
	printf("\n");
    return 0;
}
