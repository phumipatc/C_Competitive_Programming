/*
    TASK :
    AUTHOR : Boss
    SCHOOL : RYW
    LANG : C++
*/
#include <cstdio>
#define MODNUM  93563
int compute(int n, int k){
	if(k==1){
		if(n==1)
			return 1;
		else
			return 0;
	}
	int ans = 1,i;
	for(i=0; i<n-1; i++)
		ans = ((ans*(k-1)) % MODNUM);
	ans = (ans*k) % MODNUM;
	return ans;
}

int main(){
	int t,n,k,a,b,tt,i;
	scanf("%d",&t);
	for(tt=0;tt<t;tt++){
		scanf("%d %d",&n,&k);
		for(i=0; i<n-1; i++)
			scanf("%d %d",&a,&b);
		printf("%d\n",compute(n,k));
	}
	return 0;
}
