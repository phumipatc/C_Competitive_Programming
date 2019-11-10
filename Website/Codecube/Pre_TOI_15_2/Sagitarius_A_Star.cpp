/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long u,v,w,id;
    bool operator < (const A&o) const{
        return w<o.w;
    }
};
A now;
priority_queue<A > heap,unuse;
long long p[100010],anss[100010];
long long find_root(long long n){
    if(p[n] == n)   return n;
    else            return p[n] = find_root(p[n]);
}
int main(){
    long long n,m,u,v,w,ru,rv,opr,idx = 1;
    scanf("%lld %lld",&n,&m);
    for(long long i=1;i<=n;i++)
        p[i] = i;
    for(long long i=1;i<=m;i++){
        scanf("%lld %lld %lld",&u,&v,&w);
        heap.push({u,v,w,i});
    }
    scanf("%lld",&opr);
    long long ans = 0;
    while(!heap.empty()){
        now = heap.top();
        heap.pop();
        ru = find_root(now.u);
        rv = find_root(now.v);
        if(ru == rv){
            unuse.push(now);
            continue;
        }
        p[ru] = rv;
        ans+=now.w;
        anss[idx++] = now.id;
    }
    rv = find_root(1);
    for(long long i=2;i<=n;i++){
        ru = find_root(i);
        if(ru!=rv){
            printf("-1\n");
            return 0;
        }
    }
    if(unuse.empty()){
        printf("-1\n");
        return 0;
    }
    now = unuse.top();
    anss[idx++] = now.id;
    ans+=now.w;
    printf("%lld\n",ans);
    if(opr == 2){
        for(long long i=1;i<idx;i++)
            printf("%lld ",anss[i]);
    }
	return 0;
}
