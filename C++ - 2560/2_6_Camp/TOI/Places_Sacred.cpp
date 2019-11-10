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
        return w<o.w;
    }
};
A now;
priority_queue< A> heap;
long long p[200005];
long long find_root(long long idx){
    if(p[idx] == idx)   return idx;
    else                return p[idx] = find_root(p[idx]);
}
int main(){
    long long n,m,u,v,w,ru,rv,ans = 0;
    cin >> n >> m;
    for(long long i=1;i<=n;i++)
        p[i] = i;
    for(long long i=1;i<=m;i++){
        cin >> u >> v >> w;
        heap.push({u,v,w-1});
    }
    while(!heap.empty()){
        now = heap.top();
        heap.pop();
        ru = find_root(now.u);
        rv = find_root(now.v);
        if(ru!=rv){
            p[ru] = rv;
            ans+=now.w;
        }
    }
    cout << ans << endl;
    return 0;
}
