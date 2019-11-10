#include<bits/stdc++.h>
using namespace std;
struct A{
    int d,p;
    bool operator < (const A&o) const{
        return d<o.d;
    }
};
struct B{
    int v,d,t;
};
struct C{
    int v;
    long long t;
    bool operator < (const C&o) const{
        return t>o.t;
    }
};
C now;
priority_queue< C> heap;
A shoe[100005];
vector< B> g[100005];
int mark[100005],countt = 1;
int main(){
    int n,m,k,t,u,v,d,tt;
    scanf("%d %d %d %d",&n,&m,&k,&t);
    for(int i=1;i<=m;i++){
        scanf("%d %d %d %d",&u,&v,&d,&tt);
        g[u].push_back({v,d,tt});
        g[v].push_back({u,d,tt});
    }
    for(int i=1;i<=k;i++)
        scanf("%d %d",&shoe[i].p,&shoe[i].d);
    sort(shoe+1,shoe+k+1);
    shoe[k+1].p = shoe[k].p*2;
    shoe[k+1].d = shoe[k].d*2;
    for(int i=k;i>=1;i--){
        shoe[i].p = min(shoe[i].p,shoe[i+1].p);
    }
    int p = 1,q = k+1,limit,mid;
    while(p<q){
        mid = (p+q)/2;
        limit = shoe[mid].d;
        heap.push({1,0});
        while(!heap.empty()){
            now = heap.top();
            heap.pop();
            if(mark[now.v] == countt)   continue;
            mark[now.v] = countt;
            for(int i=0;i<g[now.v].size();i++){
                if(g[now.v][i].d>limit) continue;
            }
        }
        countt++;
    }
    return 0;
}
