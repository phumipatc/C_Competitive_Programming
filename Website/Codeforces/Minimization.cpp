/*
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long v,w,k;
    bool operator < (const A&o) const{
        return w<o.w;
    }
};
A now;
queue<A > que;
long long a[300010];
unordered_map<long long ,long long > mark[300010];
int main(){
    long long n,k,ans = 0;
    scanf("%lld %lld",&n,&k);
    for(long long i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    for(long long i=1;i<n;i++)
        ans+=a[i+1]-a[i];
    que.push({n,0,n%k});
    long long maxx = 0;
    while(!que.empty()){
        now = que.front();
        que.pop();
        // printf("%lld %lld %lld\n",now.v,now.w,now.k);
        if(now.v<(n/k))                 continue;
        int ch = mark[now.v][now.k];
        if(ch && ch>=now.w)             continue;
        mark[now.v][now.k] = now.w;
        if(now.v == n/k){
            if(now.k == 0)  maxx = max(maxx,now.w);
            continue;
        }
        if(now.v == (n/k)+1){
            if(now.k == 1)  maxx = max(maxx,now.w);
            continue;
        }
        if(now.k)   que.push({now.v-(n/k)-1,now.w+a[now.v-(n/k)]-a[now.v-(n/k)-1],now.k-1});
        que.push({now.v-(n/k),now.w+a[now.v-(n/k)+1]-a[now.v-(n/k)],now.k});
    }
    printf("%lld\n",ans-maxx);
    return 0;
}