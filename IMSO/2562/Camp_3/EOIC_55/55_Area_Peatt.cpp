/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
pair<long long ,long long > p[200010];
long long dis[200010];
int main(){
    long long n,m;
    cin >> n >> m;
    if(n>5000)  return 0;
    for(long long i=1;i<=n;i++)
        cin >> p[i].first >> p[i].second;
    p[n+1].first = p[n+1].second = m;
    for(long long i=1;i<=n+1;i++)
        dis[i] = 1e18;
    for(long long k=1;k<=10;k++){
        for(long long i=0;i<=n;i++){
            for(long long j=1;j<=n+1;j++){
                if(i == j)  continue;
                if(p[j].first<p[i].first || p[j].second<p[i].second)    continue;
                dis[j] = min(dis[j],dis[i]+(p[j].first-p[i].first)*(p[j].second-p[i].second));
            }
        }
    }
    printf("%lld\n",dis[n+1]);
	return 0;
}