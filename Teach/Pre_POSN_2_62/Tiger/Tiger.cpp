/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;
map<long long ,long long > mapp;
pair<long long ,long long > p[1010],pos;
long long dist(pair<long long ,long long > a,pair<long long ,long long > b){
    return abs(a.x-b.x)+abs(a.y-b.y);
}
int main(){
	freopen("10.in","r",stdin);
	freopen("10.sol","w",stdout);
    long long n,m,minn,maxx = 0;
    scanf("%lld %lld",&n,&m);
    for(long long i=1;i<=n;i++)
        scanf("%lld %lld",&p[i].x,&p[i].y);
    for(long long i=1;i<=m;i++){
        scanf("%lld %lld",&pos.x,&pos.y);
        minn = 1e18;
        for(long long j=1;j<=n;j++)
            minn = min(minn,dist(pos,p[j]));
        mapp[minn]++;
        maxx = max(maxx,mapp[minn]);
		// printf("%lld\n",maxx);
    }
    printf("%lld\n",maxx);
	return 0;
}