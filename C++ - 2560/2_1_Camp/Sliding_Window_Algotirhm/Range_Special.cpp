/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
deque<pair<long long,long long> > minn,maxx;
long long a[10000020];
int main()
{
    long long n,p,q;
    scanf("%lld %lld %lld",&n,&p,&q);
    long long sum,now,sump,sumq,cur;
    sum=cur=sump=sumq=0;
    for(long long i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    for(long long i=1;i<=n;i++){
        while(!minn.empty() && minn.back().second>a[i])    minn.pop_back();
        while(!maxx.empty() && maxx.back().second<a[i])    maxx.pop_back();
        minn.push_back(make_pair(i,a[i]));
        maxx.push_back(make_pair(i,a[i]));
        while(!minn.empty() && !maxx.empty()){
            if(maxx.front().second-minn.front().second<=q)  break;
            if(maxx.front().first<minn.front().first)       cur=maxx.front().first,maxx.pop_front();
            else                                            cur=minn.front().first,minn.pop_front();
        }
        sumq+=i-cur;
    }
    while(!maxx.empty())    maxx.pop_back();
    while(!minn.empty())    minn.pop_back();
    cur=0;
    for(long long i=1;i<=n;i++){
        while(!minn.empty() && minn.back().second>a[i])    minn.pop_back();
        while(!maxx.empty() && maxx.back().second<a[i])    maxx.pop_back();
        minn.push_back(make_pair(i,a[i]));
        maxx.push_back(make_pair(i,a[i]));
        while(!minn.empty() && !maxx.empty()){
            if(maxx.front().second-minn.front().second<p)  break;
            if(maxx.front().first<minn.front().first)       cur=maxx.front().first,maxx.pop_front();
            else                                            cur=minn.front().first,minn.pop_front();
        }
        sump+=i-cur;
    }
    printf("%lld\n",sumq-sump);
    return 0;
}
/*
7 4 6
1 7 4 3 9 6 8
*/
