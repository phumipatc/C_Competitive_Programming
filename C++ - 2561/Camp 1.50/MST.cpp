/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int u,v;
    double w;
    bool operator < (const A&o) const{
        return w>o.w;
    }
};
A now;
priority_queue< A> heap;
int p[1010];
int find_root(int n){
    if(p[n] == n)   return n;
    else            return p[n] = find_root(p[n]);
}
int main(){
    int n,m,u,v,ru,rv;
    double w,ans = 0;
    scanf("%d %d",&n,&m);
    while(m--){
        scanf("%d %d %lf",&now.u,&now.v,&now.w);
        heap.push(now);
    }
    for(int i=0;i<n;i++)   p[i] = i;
    while(!heap.empty()){
        now = heap.top();
        heap.pop();
        ru = find_root(now.u);
        rv = find_root(now.v);
        if(ru == rv)    continue;
        p[ru] = rv;
        ans+=now.w;
    }
    printf("%.3lf\n",ans);
	return 0;
}
