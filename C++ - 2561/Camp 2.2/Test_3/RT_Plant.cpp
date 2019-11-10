/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
pair<long long ,long long > p[100010];
long long qs[100010];
int main(){
    long long n,a,b,minn,maxx = -1e18;
    scanf("%lld %lld %lld",&n,&a,&b);
    for(long long i=1;i<=n;i++){
        scanf("%lld %lld",&p[i].first,&p[i].second);
        p[i].second*=-1;
    }
    sort(p+1,p+n+1);
    maxx = max(maxx,a*(-p[1].second));
    minn = b*p[1].first;
    qs[1] = -p[1].second;
    for(int i=1;i<=n;i++)
        p[i].second*=(-1);
    for(long long i=2;i<=n;i++){
        qs[i] = qs[i-1]+p[i].second;
        maxx = max(maxx,a*qs[i]-b*p[i].first+minn);
        minn = max(minn,-1*a*qs[i-1]+b*p[i].first);
    }
    printf("%lld\n",maxx);
    return 0;
}
