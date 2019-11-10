/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long v,w,sp,last,cnt;
    bool operator < (const A&o) const{
        return w>o.w;
    }
};
A now;
vector< A> g[80010];
priority_queue< A> heap;
long long dis[10][80010],potion[80010];
long long sp[10] = {1,2,4,8,16,32,64,128,256};
int main(){
    long long n,m,l,q,u,v,w,ans = 1e18;
    scanf("%lld %lld %lld %lld",&n,&m,&l,&q);
    for(long long i=1;i<=m;i++){
        scanf("%lld %lld %lld",&u,&v,&w);
        g[u].push_back({v,w,0,0,0});
    }
    for(long long i=1;i<=l;i++){
        scanf("%lld",&u);
        potion[u] = 1;
    }
    for(long long i=0;i<=8;i++)
        for(long long j=1;j<=n;j++)
            dis[i][j] = 1e18;
    heap.push({1,0,0,0,0});
    dis[0][1] = 0;
    while(!heap.empty()){
        now = heap.top();
        heap.pop();
        for(auto &x:g[now.v]){
            if(potion[now.v] && now.last!=now.v && now.cnt<q){
                if(dis[now.cnt+1][x.v] > now.w+(x.w/sp[now.sp+1])){
                    dis[now.cnt+1][x.v] = now.w+(x.w/sp[now.sp+1]);
                    heap.push({x.v,dis[now.cnt+1][x.v],now.sp+1,now.v,now.cnt+1});
                }
            }
            if(dis[now.cnt][x.v] > now.w+(x.w/sp[now.sp])){
                dis[now.cnt][x.v] = now.w+(x.w/sp[now.sp]);
                heap.push({x.v,dis[now.cnt][x.v],now.sp,now.last,now.cnt});
            }
        }
    }
    for(long long i=0;i<=8;i++)
        ans = min(ans,dis[i][n]);
    printf("%lld\n",ans);
    return 0;
}
