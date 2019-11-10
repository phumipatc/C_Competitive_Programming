/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include <bits/stdc++.h>

using namespace std;
struct A{
    int i, va;
    bool operator<( const A &o )const{
        return va < o.va;
    }
};
int n, m, idx[3010], dp[3010], value[3010];
vector<int> g[3010];
vector<A> v;
queue<int> que;
int main()
{
    scanf("%d %d",&n,&m);
    for( int i = 0 ; i < n ; i++ )
    {
        scanf("%d",&value[i]);
        v.push_back({ i, value[i] });
    }
    sort( v.begin(), v.end() );
    for( int i = 0 ; i < n ; i++ )
        value[v[i].i] = i;
    int l = 1, r = n-1;
    while( l < r ){
        int mid = ( l + r ) / 2;
        for( int i = 0 ; i < 3010 ; i++ ){
            g[i].clear();
            idx[i] = 0, dp[i] = 0;
        }
        for( int i = 0 ; i < n ; i++ ){
            for( int j = 1 ; j <= mid ; j++ ){
                if( v[value[i]] < v[value[(i+j)%n]] ){
                    g[value[i]].push_back( value[(i+j)%n] );
                    idx[value[(i+j)%n]]++;
                }
            }
        }
        for( int i = 0 ; i < n ; i++ ){
            if( idx[i] == 0 ){
                que.push( i );
                dp[i] = 1;
            }
        }
        while( !que.empty() ){
            int now = que.front();
            que.pop();
            for( int i = 0 ; i < g[now].size() ; i++ ){
                idx[g[now][i]]--;
                if( idx[g[now][i]] == 0 )
                    que.push( g[now][i] );
                dp[g[now][i]] = max( dp[g[now][i]], dp[now] + 1 );
            }
        }
        int maxx = 0;
        for( int i = 0 ; i < n ; i++ )
            maxx = max( maxx, dp[i] );
        if(maxx>=m+1)   r = mid;
        else            l = mid + 1;
    }
    printf("%d",l);
    return 0;
}