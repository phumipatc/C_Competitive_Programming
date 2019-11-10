/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long v,w,x;
    bool operator < (const A&o) const{
        if(w!=o.w)  return w>o.w;
        else        return x>o.x;
    }
};
struct B{
    long long num,constraint;
};
A now;
priority_queue<A > heap;
vector<A > g[510];
vector<B > ans;
long long dis[510][10010];
char str[10];
int main(){
    long long n,m,u,v,num,q,ch;
    scanf("%lld %lld",&n,&m);
    for(long long i=1;i<=m;i++){
        scanf("%lld %lld %s",&u,&v,str);
        if(str[0] == 'x'){
            num = 0;
            g[u].push_back({v,num,1});
            continue;
        }
        num = atoll(str);
        g[u].push_back({v,num,0});
    }
    scanf("%lld",&q);
    while(q--){
        scanf("%lld %lld",&u,&v);
        for(long long i=1;i<=n;i++)
            for(long long j=0;j<=m;j++)
                dis[i][j] = 1e9;
        dis[u][0] = 0,ch = 0;
        heap.push({u,0,0});
        while(!heap.empty()){
            now = heap.top();
            heap.pop();
            if(now.v == v){
                ch = 1;
                continue;
            }
            for(auto x:g[now.v]){
                if(now.x+x.x>m)                     continue;
                if(dis[x.v][now.x+x.x]<=now.w+x.w)  continue;
                dis[x.v][now.x+x.x] = now.w+x.w;
                heap.push({x.v,now.w+x.w,now.x+x.x});
            }
        }
        if(ch == 0){
            printf("0 0\n");
            continue;
        }
        if(dis[v][0] == 1e9){
            printf("inf\n");
        }
    }
	return 0;
}
