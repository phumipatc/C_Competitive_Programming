#include <bits/stdc++.h>
using namespace std;
long long n, l, q;
long long sumup, sumdown, numup, numdown;
long long up[1000100], down[1000100], flip[1000100];
int base[1000100];
void up1( int idx, long long val )
{
	for( int i = idx + 1 ; i <= 1e6 + 25 ; i += ( i & -i ) )up[i] += val;
}
void up2( int idx, long long val ){
	for( int i = idx + 1 ; i <= 1e6 + 25 ; i += ( i & -i ) )down[i] += val;
}
long long query1( int x )
{
	long long sum = 0 ;
	for( int i = x + 1 ; i > 0 ; i -= ( i & -i ) )sum += up[i];
	return sum;
}
long long query2( int x )
{
	long long sum = 0 ;
	for( int i = x + 1 ; i > 0 ; i -= ( i & -i ) )sum += down[i];
	return sum;
}
int main()
{
	scanf("%lld %lld %lld",&n,&l,&q);
	up1( ( int )l, n );
	sumup = l*n;
	numup = n;
	for( int i = 1 ; i <= n ; i++ )base[i] = ( int )l;
	while( q-- ){
		char c;
		int a;
		long long x, b;
		scanf(" %c",&c);
		if( c == 's' ){
			scanf("%d %lld",&a,&b);
			a++;
			if( flip[a] == 0 ){
				up1( base[a], -1 );
				sumup -= base[a];
			}

			else{
				up2( base[a], -1 );
				sumdown -= base[a];
			}
			base[a] += b;
			if( base[a] > l || ( base[a] == l && flip[a] == 1 ) )base[a] %= l;
			if( flip[a] == 0 ){
				up1( base[a], 1 );
				sumup += base[a];
			}
			else{
				up2( base[a], 1 );
				sumdown += base[a];
			}
		}
		else if( c == 'f' ){
			scanf("%d",&a);
			a++;
			if( flip[a] == 0 ){
				sumup -= base[a];
				up1( base[a], -1 );
				if( base[a] == l )base[a] = 0;
				sumdown += base[a];
				up2( base[a], 1 );
				numup--, numdown++;
			}
			else{
				sumdown -= base[a];
				up2( base[a], -1 );
				if( base[a] == 0 )base[a] = l;
				sumup += base[a];
				up1( base[a], 1 );
				numdown--, numup++;
			}
			flip[a] ^= 1; 
		}
		else{
			scanf("%lld",&x);
			long long allup = x*numup - sumup + l * ( numup - query1( (int)x - 1 ) ), alldown = sumdown - x*numdown + l * query2( (int)x );
			printf("%lld\n",alldown + allup );
		}
	}
	return 0;
}