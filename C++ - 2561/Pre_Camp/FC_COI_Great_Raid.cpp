/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int u,v,w;
    bool operator < (const A&o) const{
        return w>o.w;
    }
};
A now;
priority_queue<A > heap;
int a[100010],p[100010];
int find_root(int n){
    if(p[n] == n)   return n;
    else            return p[n] = find_root(p[n]);
}
int main(){
    int n,m,u,v,ru,rv,ans = 0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]),p[i] = i;
    scanf("%d",&m);
    while(m--){
        scanf("%d %d",&u,&v);
        heap.push({u,v,a[u]+a[v]});
    }
    while(!heap.empty()){
        now = heap.top();
        heap.pop();
        ru = find_root(now.u);
        rv = find_root(now.v);
        if(ru == rv)    continue;
        ans+=now.w;
        p[ru] = rv;
    }
    printf("%d\n",ans);
	return 0;
}
