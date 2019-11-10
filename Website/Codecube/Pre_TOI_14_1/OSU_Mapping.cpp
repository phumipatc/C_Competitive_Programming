/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long u,w,town;
    bool operator < (const A&o) const{
        return w>o.w;
    }
};
vector< A> g[10100];
priority_queue< A> heap;
int main(){
    long long n,m,t,i,j,st,en,u,v,w,k,d;
    scanf("%lld %lld %lld %lld %lld",&n,&m,&t,&st,&en);
    for(i=1;i<=m;i++){
        scanf("%lld %lld %lld",&u,&v,&w);
        g[u].push_back({v,w,0});
    }
    heap.push({st,0,1});
    long long countt=1;
    while(!heap.empty()){
        if(countt==1000000){
            printf("-1\n");
            return 0;
        }
        u=heap.top().u,k=heap.top().town,w=heap.top().w;
        heap.pop();
        if(u==en && k%t==0){
            printf("%lld\n",w);
            return 0;
        }
        for(i=0;i<g[u].size();i++){
            heap.push({g[u][i].u,g[u][i].w+w,k+1});
        }
        countt++;
    }
    printf("-1\n");
    return 0;
}
