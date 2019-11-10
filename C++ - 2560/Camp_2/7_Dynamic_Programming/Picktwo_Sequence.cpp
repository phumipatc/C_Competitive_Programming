/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include <stdio.h>
int max(int a,int b){
	return (a>=b)?a:b;
}
int A[100010],L[100010],R[100010];
int main(){
	int n,q,cc,c,sol,run;
	scanf("%d",&q);
	for(cc = 1;cc <= q;cc++){
		scanf("%d",&n);
		for(c = 1 ; c <= n ; c++)
			scanf("%d",&A[c]);
		for(c = 0 ; c <= n+1 ; c++)
			L[c] = R[c] = 0;
		run = 0;
		for(c = 1 ; c <= n ; c++)
			run += A[c], run = max(run,0), L[c] = max(L[c-1],run);
		run = 0;
		for(c = n ; c ; c--)
			run += A[c], run = max(run,0), R[c] = max(R[c+1],run);
		sol = 0;
		for(c = 1 ; c <= n ; c++)
			sol = max(sol,L[c]+R[c+1]);
		printf("%d\n",sol);
	}
	return 0;
}
