#include <bits/stdc++.h>

using namespace std;
struct vv{
	int i, va;
	bool operator<( const vv &k )const{
		return va < k.va;
	}
};
int n, m, ind[3010], mic[3010], num[3010];
vector<int> g[3010];
vector<vv> v;
queue<int> q;
int check( int mid )
{
	for( int i = 0 ; i < 3010 ; i++ ){
		g[i].clear();
		ind[i] = 0, mic[i] = 0;
	}
	for( int i = 0 ; i < n ; i++ ){
		for( int j = 1 ; j <= mid ; j++ ){
			if( v[num[i]] < v[num[(i+j)%n]] ){
				g[num[i]].push_back( num[(i+j)%n] );
				ind[num[(i+j)%n]]++;
			}
		}
	}
	for( int i = 0 ; i < n ; i++ ){
		//printf("%d\n",ind[i]);
		if( ind[i] == 0 ){
			q.push( i );
			mic[i] = 1;
		}
	}
	/*for( int i = 0 ; i < n ; i++ ){
		printf("%d : ",i); 
		for( int j = 0 ; j < g[i].size() ; j++ ){
			printf("%d ",g[i][j]);
		}
		printf("\n");
	}*/
	while( !q.empty() ){
		int t = q.front();
		q.pop();
		//printf("%d %d\n",mid,t);
		for( int i = 0 ; i < g[t].size() ; i++ ){
			ind[g[t][i]]--;
			if( ind[g[t][i]] == 0 )q.push( g[t][i] );
			mic[g[t][i]] = max( mic[g[t][i]], mic[t] + 1 );
		}
 	}
 	int ma = 0;
 	for( int i = 0 ; i < n ; i++ ){
 		//printf("%d\n",mic[i]);
 		ma = max( ma, mic[i] );
 	}
 	if( ma >= m+1 )return 1;
 	else return 0;
}
int main()
{
	scanf("%d %d",&n,&m);
	for( int i = 0 ; i < n ; i++ ){
		scanf("%d",&num[i]);
		v.push_back({i,num[i]}); 
	}
	sort( v.begin(), v.end() );
	for( int i = 0 ; i < n ; i++ ){
		num[v[i].i] = i;
	}
	int l = 1, r = n - 1;
	while( l < r ){
		int mid = ( l + r ) / 2;
		if( check( mid ) )r = mid;
		else l = mid + 1;
	}
	printf("%d",l);
	return 0;
}