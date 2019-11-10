/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long opr,l,r,v;
};
A Q[100100];
long long comp[200100],tree[800100],lazy[800100][2];
void update(long long l,long long r,long long now,long long ll,long long rr,long long v){
    if(lazy[now][0]){
        tree[now] = (comp[r]-comp[l-1])*lazy[now][1];
        if(l!=r){
            lazy[now*2][0] = lazy[now*2+1][0] = 1;
            lazy[now*2][1] = lazy[now][1];
            lazy[now*2+1][1] = lazy[now][1];
        }
        lazy[now][0] = lazy[now][1] = 0;
    }
    if(r<ll || l>rr)    return ;
    if(ll<=l && r<=rr){
        tree[now] = (comp[r]-comp[l-1])*v;
        if(l!=r){
            lazy[now*2][0] = lazy[now*2+1][0] = 1;
            lazy[now*2][1] = v;
            lazy[now*2+1][1] = v;
        }
        return ;
    }
    long long mid = (l+r)/2;
    update(l,mid,now*2,ll,rr,v);
    update(mid+1,r,now*2+1,ll,rr,v);
    tree[now] = tree[now*2]+tree[now*2+1];
}
long long query(long long l,long long r,long long now,long long ll,long long rr){
    if(lazy[now][0]){
        tree[now] = (comp[r]-comp[l-1])*lazy[now][1];
        if(l!=r){
            lazy[now*2][0] = lazy[now*2+1][0] = 1;
            lazy[now*2][1] = lazy[now][1];
            lazy[now*2+1][1] = lazy[now][1];
        }
        lazy[now][0] = lazy[now][1] = 0;
    }
    if(r<ll || l>rr)    return 0;
    if(ll<=l && r<=rr)  return tree[now];
    long long mid = (l+r)/2;
    long long q1 = query(l,mid,now*2,ll,rr);
    long long q2 = query(mid+1,r,now*2+1,ll,rr);
    tree[now] = tree[now*2]+tree[now*2+1];
    return q1+q2;
}
int main(){
    long long n,q;
    scanf("%lld %lld",&n,&q);
    for(long long i=0;i<q;i++){
        scanf("%lld",&Q[i].opr);
        if(Q[i].opr == 0){
            scanf("%lld %lld %lld",&Q[i].l,&Q[i].r,&Q[i].v);
            comp[i*2] = Q[i].l;
            comp[i*2+1] = Q[i].r;
        }else{
            scanf("%lld %lld",&Q[i].l,&Q[i].r);
            comp[i*2] = Q[i].l;
            comp[i*2+1] = Q[i].r;
        }
    }
    sort(comp,comp+(2*q));
    long long idx = 0,l,r;
    comp[2*q] = 1e18;
    for(long long i=0;i<2*q;i++)
        if(comp[i]!=comp[i+1])
            comp[idx++] = comp[i];
    for(long long i=0;i<q;i++){
        if(Q[i].opr == 0){
            l = lower_bound(comp,comp+idx,Q[i].l)-comp+1;
            r = lower_bound(comp,comp+idx,Q[i].r)-comp;
            update(1,idx,1,l,r,Q[i].v);
        }else{
            l = lower_bound(comp,comp+idx,Q[i].l)-comp+1;
            r = lower_bound(comp,comp+idx,Q[i].r)-comp;
            printf("%lld\n",query(1,idx,1,l,r));
        }
    }
    return 0;
}
