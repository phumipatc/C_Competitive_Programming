/*
    TASK :
    AUTHOR : Boss
    SCHOOL : RYW
    LANG : C++
*/
#include <stdio.h>
const int K = 20;
int c[20];
int main(){
	int n,x,i,j;
	scanf("%d", &n);
	for(i = 0; i < n; ++i){
		scanf("%d", &x );
		for(j = 0; j < K; ++j)
			if( x&(1<<j) ) c[j]++;
	}
	long long ans = 0;
	for(i = 0; i < K; ++i )
		ans += (long long)( c[i] )*( n-c[i] )*(1<<i);
	printf("%lld\n", ans );
	return 0;
}
