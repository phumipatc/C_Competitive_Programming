/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long l,r;
};
A a[400010];
vector<long long > g[400010];
long long c[400010],pre[400010],tree[1600010],lazy[1600010];
long long idx = 1;
void dfs(long long now,long long p){
    pre[idx] = now;
    a[now].l = idx++;
    for(auto x:g[now]){
        if(x == p)  continue;
        dfs(x,now);
    }
    a[now].r = idx-1;
}
void build(long long l,long long r,long long now){
    if(l == r){
        tree[now] = 1ll<<(c[pre[l]]);
        // printf("%lld %lld %lld\n",l,r,tree[now]);
        return ;
    }
    long long mid = (l+r)/2;
    build(l,mid,now*2);
    build(mid+1,r,now*2+1);
    tree[now] = tree[now*2]|tree[now*2+1];
    // printf("%lld %lld %lld\n",l,r,tree[now]);
}
void update(long long l,long long r,long long now,long long ll,long long rr,long long v){
    if(lazy[now]){
        tree[now] = lazy[now];
        if(l!=r)    lazy[now*2] = lazy[now*2+1] = lazy[now];
        lazy[now] = 0;
        // printf("lazy: %lld %lld %lld\n",l,r,tree[now]);
    }
    if(r<ll || l>rr)    return ;
    if(l>=ll && r<=rr){
        tree[now] = v;
        if(l!=r)    lazy[now*2] = lazy[now*2+1] = v;
        // printf("target: %lld %lld %lld\n",l,r,tree[now]);
        return ;
    }
    long long mid = (l+r)/2;
    update(l,mid,now*2,ll,rr,v);
    update(mid+1,r,now*2+1,ll,rr,v);
    tree[now] = tree[now*2]|tree[now*2+1];
    // printf("updating: %lld %lld %lld %lld %lld\n",l,r,tree[now],tree[now*2],tree[now*2+1]);
}
long long query(long long l,long long r,long long now,long long ll,long long rr){
    if(lazy[now]){
        tree[now] = lazy[now];
        if(l!=r)    lazy[now*2] = lazy[now*2+1] = lazy[now];
        lazy[now] = 0;
    }
    if(r<ll || l>rr)    return 0;
    if(l>=ll && r<=rr)  return tree[now];
    long long mid = (l+r)/2;
    long long ansl = query(l,mid,now*2,ll,rr);
    long long ansr = query(mid+1,r,now*2+1,ll,rr);
    tree[now] = tree[now*2]|tree[now*2+1];
    return ansl|ansr;
}
int main(){
    long long n,m,u,v;
    scanf("%lld %lld",&n,&m);
    for(long long i=1;i<=n;i++)
        scanf("%lld",&c[i]),c[i]--;
    for(long long i=1;i<n;i++){
        scanf("%lld %lld",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0);
    build(1,n,1);
    long long opr;
    while(m--){
        scanf("%lld",&opr);
        if(opr == 1){
            scanf("%lld %lld",&u,&v);
            // printf("Update: %lld\n",1ll<<(v-1));
            update(1,n,1,a[u].l,a[u].r,1ll<<(v-1));
        }else{
            scanf("%lld",&u);
            printf("%d\n",__builtin_popcountll(query(1,n,1,a[u].l,a[u].r)));
        }
    }
	return 0;
}