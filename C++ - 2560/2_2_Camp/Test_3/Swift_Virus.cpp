/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long now,dis;
};
struct info{
    long long value,times;
    bool operator < (const info&o) const{
        return times<o.times;
    }
};
info a[100100];
long long mark[100100];
vector< long long> g[100100];
queue< A> q;
priority_queue< long long> heap;
int main(){
    long long n,m,k;
    scanf("%lld %lld %lld",&n,&m,&k);
    for(long long i=1;i<=n;i++)
        scanf("%lld",&a[i].value);
    for(long long i=1;i<=m;i++){
        long long u,v;
        scanf("%lld %lld",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    q.push({k,0});
    while(!q.empty()){
        A temp=q.front();
        q.pop();
        if(mark[temp.now])  continue;
        mark[temp.now]=1;
        a[temp.now].times=temp.dis;
        for(long long i=0;i<g[temp.now].size();i++)
            q.push({g[temp.now][i],temp.dis+1});
    }
    long long ans=0;
    for(int i=1;i<=n;i++)
        if(mark[i]==0 && a[i].value>0)
            ans+=a[i].value;
    sort(a+1,a+n+1);
    for(long long i=1;i<=n;i++){
        if(a[i].value<=0)   continue;
        if(heap.size()<a[i].times)
            heap.push(a[i].value*(-1));
        else if(!heap.empty() && heap.top()*(-1)<a[i].value){
            heap.pop();
            heap.push(a[i].value*(-1));
        }
    }
    while(!heap.empty()){
        ans+=(heap.top()*(-1));
        heap.pop();
    }

    printf("%lld\n",ans);
    return 0;
}
