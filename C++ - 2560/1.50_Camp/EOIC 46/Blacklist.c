/*
TASK: Blacklist
LANG: C++
AUTHOR:
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
const int MAX = 1000005;
long long a, b, period = 1ll;
int cards[MAX], overflow = 0,n, c, d, num[MAX];
int shuffle( int r, int s, int level ) {
	if( r == s  &&  level > 0 ) return level;
	return( cards[s] = shuffle( r, num[s], level + 1 ));
}
long long gcd( long long a, long long b ) {
	if(b==0)	return a;
	return gcd(b,a%b);
}
long long solve( long long x ) {
	return( ( x + period - 1 ) / period );
}
int main() {
	scanf("%d %lld %lld %d %d", &n, &a, &b, &c, &d );
	for( int i = 1; i <= n; ++i )
		scanf( "%d", &num[i] );
	memset( cards, -1, sizeof( cards ) );
	for( int i = 1; i <= n; ++i )
		if( cards[i] == -1 )
			shuffle(i, i, 0 );
	for( int i = c+1; i <= n-d; ++i ) {
		period = (period * cards[i]) / gcd(period,cards[i]);
		if( period > b ) { overflow = 1; break; }
	}
	printf("%lld\n",(overflow ? 0 : solve(b)-solve(a-1)));
	return 0 ;
}

