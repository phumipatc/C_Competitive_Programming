/*
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
priority_queue<A > heap;
int p[1010];
int fr(int i){
    if(i == p[i])   return i;
    else            return p[i] = fr(p[i]);
}
int main(){
    int n,m,u,v,ru,rv;
    double w,ans = 0;
    cin >> n >> m;
    for(int i=0;i<n;i++)
        p[i] = i;
    while(m--){
        cin >> u >> v >> w;
        heap.push({u,v,w});
    }
    while(!heap.empty()){
        now = heap.top();
        heap.pop();
        ru = fr(now.u);
        rv = fr(now.v);
        if(ru!=rv){
            p[ru] = rv;
            ans+=now.w;
        }
    }
    printf("%.3lf\n",ans);
	return 0;
}
