/*
TASK: Worm
AUTHOR: PeaTT~
LANG: C
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct{
	long long d,c;
}worm;
worm w[100010];

long long sum,ansd,ansc;

int sort(const void* a,const void* b){
	worm *p,*q;
	p=(worm*)a;
	q=(worm*)b;
	if(((worm*)p)->c == ((worm*)q)->c)
		return ((worm*)p)->d - ((worm*)q)->d;
	return ((worm*)p)->c - ((worm*)q)->c;
}

int main(){
	long long i,n;
	double max;
	scanf("%lld",&n);
	for(i=0;i<n;i++)
		scanf("%lld %lld",&w[i].d,&w[i].c);
	qsort(w,n,sizeof(w[0]),sort);
	sum=w[0].d;
	max=(double)w[0].d/w[0].c;
	ansd=sum;
	ansc=w[0].c;
	for(i=1;i<n;i++){
		sum+=w[i].d;
		if((double)sum/w[i].c > max){
			max = (double)sum/w[i].c;
			ansd = sum;
			ansc = w[i].c;
		}
	}
	printf("%lld %lld\n",ansd,ansc);
	return 0;
}
