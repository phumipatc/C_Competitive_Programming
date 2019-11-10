/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long u,v,w;
    bool operator < (const A&o) const{
        return w>o.w;
    }
};
A now;
priority_queue< A> heap;
long long a[21][21],p[21];
long long find_root(long long idx){
    if(p[idx] == idx)   return idx;
    else                return p[idx] = find_root(p[idx]);
}
int main(){
    long long n,k,ans = 0,ru,rv;
    scanf("%lld %lld",&n,&k);
    long long countt = n;
    for(long long i=1;i<=n;i++){
        for(long long j=1;j<=n;j++){
            scanf("%lld",&a[i][j]);
            if(i!=j)    heap.push({i,j,a[i][j]});
        }
    }
    for(long long i=1;i<=n;i++)   p[i] = i;
    while(!heap.empty()){
        now = heap.top();
        heap.pop();
        ru = find_root(now.u);
        rv = find_root(now.v);
        if(ru!=rv){
            p[rv] = ru;
            countt--;
            ans+=now.w;
        }
        if(countt == k) break;
    }
    printf("%lld\n",ans);
    return 0;
}
