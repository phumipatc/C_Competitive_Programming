/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int u,v,w,r;
    bool operator < (const A&o) const{
        return w>o.w;
    }
};
A a[1000010];
A now;
priority_queue<A > heap;
struct B{
    int w,v;
    bool operator < (const B&o) const{
        return w<o.w;
    }
};
B b[100010];
int p[1010],c[100010];
int find_root(int now){
    if(p[now] == now)   return now;
    else                return p[now] = find_root(p[now]);
}
int main(){
    int n,m,k,u,v,w,r;
    cin >> n >> m >> k;
    for(int i=1;i<=n;i++)
        p[i] = i;
    for(int i=1;i<=m;i++)
        cin >> a[i].u >> a[i].v >> a[i].w >> a[i].r;
    for(int i=1;i<=k;i++)
        cin >> b[i].w >> b[i].v;
    sort(b+1,b+k+1);
    for(int i=k-1;i>=1;i--)
        b[i].v = min(b[i].v,b[i+1].v);
    for(int i=1;i<=k;i++)
        c[i] = b[i].w;
    int ru,rv;
    for(int i=1;i<=m;i++){
        if(a[i].r){
            ru = find_root(a[i].u);
            rv = find_root(a[i].v);
            p[ru] = rv;
            continue;
        }
        int idx = lower_bound(c+1,c+k+1,a[i].w)-c;
        heap.push({a[i].u,a[i].v,b[idx].v,0});
    }
    int ans = 0;
    while(!heap.empty()){
        now = heap.top();
        heap.pop();
        ru = find_root(now.u);
        rv = find_root(now.v);
        if(ru == rv)    continue;
        p[ru] = rv;
        ans+=now.w;
    }
    cout << ans << endl;
	return 0;
}
/*
10 13 7
1 7 7 1
1 4 53 0
4 2 27 0
5 8 12 1
7 5 77 0
5 9 6 1
10 6 91 0
2 10 23 1
3 4 34 1
7 9 52 0
3 5 97 0
4 8 98 0
9 8 75 0
67 472
55 334
14 360
12 118
99 430
54 671
30 755
*/
