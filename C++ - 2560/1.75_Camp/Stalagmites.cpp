/*
    TASK :
    AUTHOR : Boss
    SCHOOL : RYW
    LANG : C++
*/
#include <stdio.h>
#define MAXH 500000
int main(){
	int N, H, i;
	static int a[MAXH+1], b[MAXH+1];
	int c1, c2;
	scanf("%d%d", &N, &H );
	for(i=0; i<=H; ++i)
		a[i] = b[i] = 0;
	for(i=0; i<N; ++i){
		int x;
		scanf("%d", &x );
		if(i%2 == 0)	++b[x];
		else			++a[x];
	}
	for(i=H-1; i>0; --i){
		a[i] += a[i+1];
		b[i] += b[i+1];
	}
	c1 = N+1; c2 = -1;
	for(i=1; i<=H; ++i ){
		int temp = b[i] + a[H-i+1];
		if( temp < c1 )
			c1 = temp,c2 = 1;
		else if ( temp == c1 )
			++c2;
	}
	printf( "%d %d\n", c1, c2 );
	return 0;
}
